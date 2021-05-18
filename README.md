# An Infer wrapper that corrects shortcomings in Infer's incremental analysis

Updated source of the Infer wrapper can be download from [here](https://github.com/TomasBeranek/infer-wrapper-for-incremental-analysis). The experiment was tested on Infer v1.1.0.

# Usage
The wrapper is called instead of Infer's binary, when invoking the ```infer analyze``` command, for example:

```
  infer-inc analyze --pulse --bufferoverun
```

To omit reported issues only the files that were analysed, add the ```--incremental-report``` option anywhere in the command, for example:

```
  infer-inc --incremental-report analyze --pulse --bufferoverun
```

## Limitations
- the analysed project must contain exactly one ```main``` function
- the analysed project must be written in C or C++
- the wrapper looks for Infer's database in ```infer-out``` directory located in the current directory

## Experiment
The repository also contains an experiment that demonstrates Infer's shortcomings. The detailed description of the experiment is in ```experiment/README.txt```.
