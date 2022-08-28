# Build
docker build . -t cppdock:1.0

# Run
docker run -it -v"$(pwd):/project" --rm cppdock:1.0

# Delete
docker rmi -f cppdock:1.0
