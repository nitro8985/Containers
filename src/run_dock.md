docker build . -t mydock:1.0
docker run -it -v"$(pwd):/project" --rm mydock:1.0
