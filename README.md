# UAM Simulator

Running ROS2 Foxy on 20.04

## Commands

Build image with the name `foxy-uam` and tag `v1`
```
docker build -t foxy-uam:v1  .
```

Run container
```
docker run -it foxy-uam:v1
```

List all images
```
docker image ls
```


Delete all images except `foxy-uam`
```
docker image prune -a --force --filter "repository!=foxy-uam"
```

## Configuring Display

Run the following on your host terminal
```
xhost + local:
```

Check the output of `echo $DISPLAY` and change it in the Dockerfile.