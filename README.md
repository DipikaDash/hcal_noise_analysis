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

You can write a script in the `src` directory. Take `src/hbhe_fiter.cxx` as an example. Once you have wrote script, build the package again, `./complie.sh`  to get an executable which will be generated in `run`. For `src/hbhe_fiter.cxx` the executable will be `run/hbhe_filter.exe`. Now you can run it by `./run/hbhe_filter.exe`.
