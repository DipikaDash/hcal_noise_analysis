HCAL noise analysis code 
================================================ 

This is a package for CMS HCAL noise analysis.  

## Build the package

``` 
git clone git@github.com:jaehyeok/hcal_noise_analysis 
cd hcal_noise_analysis
./compile.sh
``` 
To clean and rebuild the package, do 

``` 
./compile.sh clean
./compile.sh
``` 

## Script to run 

You can write a script in the `src` directory. Look into `src/hbhe_fiter.cxx` for an example. Once you have wrote script, build the package again, `./complie.sh` to get the executable which will be generated in `run`. If you create a script called `src/new_script.cxx` then the name of the executable will be `run/new_script.exe`. For `src/hbhe_fiter.cxx` the executable will be `run/hbhe_filter.exe` which can be run by `./run/hbhe_filter.exe`.
