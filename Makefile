
.PHONY: book clean actions repo2docker binder devcontainer

book:
	@echo "Building book with jupyter-book"
	jupyter-book build -v ./

# Check https://github.com/nektos/act/issues/1658
actions:
	@echo "Running local actions"
	@echo "Do not forget to have docker running and also : sudo ln -s ~/.docker/run/docker.sock /var/run/docker.sock"
	act # act --secret-file .secrets -v --container-architecture linux/amd64

binder:
	@echo "Building binder image"
	docker build ./  -f ./Dockerfile  -t bindertest
	docker run -it --rm -p 8888:8888 bindertest jupyter notebook --NotebookApp.default_url=/lab/ --ip=0.0.0.0 --port=8888 --allow-root

repo2docker:
	@echo "Building docker image with repo2docker"
	repo2docker --user-id 1000 --user-name jovyan --debug --image-name r2d ./

devcontainer:
	@echo "Building and running  devcontainer image "
	devcontainer build --workspace-folder ./ --image-name devcontest
	docker run -it devcontest /bin/bash

clean:
	rm -f *~ #_build
