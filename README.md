[![Travis Build Status](https://travis-ci.org/gnuton/vitasdk-docker-testapp-trevis.svg?branch=master)](https://travis-ci.org/gnuton/vitasdk-docker-testapp-trevis)

# CI Script for CPP Apps
If you are a vita developer and you are willing to setup CI (Continuos Integration) for your project you are in the right place.

### Features:  
  ✔ VitaSDK is pre-installed in [docker](https://github.com/gnuton/vitasdk-docker) images for a quicker builds  
  ✔ VitaSDK is updated to the latest nightly
  ✔ TravisCI can run your unit tests
  ✔ No broken builds
  ✔ You can tag releases which get builds and the VPK gets uploaded as release.

### Basic Setup
1. Get a http://travis-ci.org account
2. Copy the .travis.yaml file in your github project
3. Edit the .travis.yaml and the script in scripts/travis/ if needed. You can most probably skip this step if you use CMake

## Releases
TravisCI can create releases when you tag commits.

### Setup releases
The releases are managed by the deploy step in the travis file.
The travis file for releases looks like this
```
deploy:
  provider: releases
  api_key: "$GH_TOKEN"
  file: 
   - "app/build/hello_cpp_world.vpk"
  skip_cleanup: true
  on:
    tags: true
```
Here the only thing you need to change is the hello_cpp_world.vpk with the name of your vpk/skprx or whatever file.  
To allow TravisCI to upload releases you must create a GH_TOKEN variable in the travisCI Buuild and fill it with the token you can get from your github.

### Create releases
Just tag your commit and push them to github.. TravisCI will take care of the rest.
```
git tag v1.0
git push --tag
```
Then you will see your code building in https://travis-ci.org/gnuton/vitasdk-docker-testapp-trevis
