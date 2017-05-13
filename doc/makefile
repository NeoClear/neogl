dd = pandoc -o
all: window.html

window.html: window.md
	$(dd) window.html window.md

.PHONY: clean

clean:
	-rm -rf *.html
