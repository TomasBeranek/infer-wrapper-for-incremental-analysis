The following experiment demonstrates shortcomings in the Infer's incremental
analysis and shows functional the wrapper over Infer that fixes the shortcomings.
The experiment was tested on the 1.1.0 version.


Every source file contains a DEAD_STORE error. Reporting it helps us to
determine which files have been analyzed. Every file contains only one function.

1) Run a full program analysis:

      infer -- make

   The report should contain:

    4x DEAD_STORE -- from each file.
    1x NULL_DEREFERENCE -- from callee.c.

2) Change the return value of the function f() from 1 to 2 on line 18 in the
file changed.c.

   This change will cause a NULL_DEREFERENCE in its indirect caller -- the
   function main().

   With incremental analysis, Infer should analyze f() and main(), and so the
   following errors should be reported:

    4x DEAD_STORE - from each file.
    2x NULL_DEREFERENCE - from main.c (new bug) and callee.c.

   Run an incremental analysis with the modified file changed.c:

      infer --reactive --changed-files-index changed_files.txt --incremental-analysis -- make

   The output of the previous command is:

    2x DEAD_STORE - from callee.c and constant.c.
    1x NULL_DEREFERENCE - from callee.c -> the newly introduced bug was missed!

3) Run the same experiment with the Infer wrapper.

      Now change the return value of the function f() back to 1 and reset the
      experiment:

        make reset

      Run a full program analysis:

        infer -- make

      Change the return value of the function f() from 1 to 2. And run the Infer's
      capture phase to capture the changed file.

        infer capture --reactive -- make

      Now use the wrapper in the same as 'infer analyze', except substitute the 'infer'
      for the wrapper:

        ../infer-inc analyze

      The output of the previous command is:

        4x DEAD_STORE - from each file.
        2x NULL_DEREFERENCE - from callee.c and the newly introduced defect from main.c.
