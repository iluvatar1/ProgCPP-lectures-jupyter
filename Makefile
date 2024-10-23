
.PHONY: book clean actions

book:
	@echo "Building book with jupyter-book"
	jupyter-book build -v ./

# Check https://github.com/nektos/act/issues/1658
actions:
	@echo "Running local actions"
	@echo "Do not forget to have docker running and also : sudo ln -s ~/.docker/run/docker.sock /var/run/docker.sock"
	act # act --secret-file .secrets -v --container-architecture linux/amd64

clean:
	rm -rf *~ #_build
