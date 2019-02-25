[![Travis Build Status](https://travis-ci.org/gnuton/vitasdk-docker-testapp-trevis.svg?branch=master)](https://travis-ci.org/gnuton/vitasdk-docker-testapp-trevis)

# Travis CI for PSVita homebrews and plugins
An easy solution for PSVita developers willing to setup CI (Continuous Integration) for their project.

### Features:
  ✔ Travis builds all pull requests before merging them to the master line  
  ✔ Travis can build releases and push them to github  
  ✔ TravisCI can run your unit tests (if any)  
  ✔ Notifications on successful or unsuccessful builds [TODO]  
  ✔ Fast builds thanks to [docker](https://github.com/gnuton/vitasdk-docker)   
  ✔ Builds against VitaSDK nightly snapshots  
  ✔ This template for CMake built code (kernel modules/apps)  

### Basic Setup
1. Get a token from https://github.com/settings/tokens with permissions (public_repo, repo_deployment)
2. Copy .travis.yaml and script directory in your repository
3. Update the copied files as needed (usually you need to replace 'app' with the dir which contains your source code)
4. Log in https://travis-ci.org/ by pressing "sign-in with github" button
5. Once logged, on the left side there is "My Repositories" > press +
6. From the list of your repositories enable the your repository
7. Then press settings and add GH_TOKEN variable to "Environment Variables" 

### Setup releases
The releases are managed by the deploy step in the travis file.
The travis file for releases looks like this:
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
The only thing you have to change is hello_cpp_world.vpk with the name of your vpk/skprx or whatever file.  
To allow TravisCI to upload releases you must create a GH_TOKEN variable in the travisCI Build and fill it with the token you can get from your [github](https://github.com/settings/tokens) as described in the step 7 of basic setup.

### Create releases
Just tag your commit and push it to github. TravisCI will take care of the rest (pushing commit, building then making a Release).
```
git tag v1.0
git push --tag
```
Then you will see your code building in https://travis-ci.org/gnuton/vitasdk-docker-testapp-trevis
