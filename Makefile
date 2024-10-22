
.PHONY: book clean

book:
	@echo "Building book with jupyter-book"
	jupyter-book build -v ./

clean:
	rm -rf *~ #_build
