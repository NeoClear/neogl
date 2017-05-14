dd = pandoc -o
all: window.html group.html widget.html

window.html: window.md
	$(dd) window.html window.md
group.html: group.md
	$(dd) group.html group.md
widget.html: widget.md
	$(dd) widget.html widget.md



.PHONY: clean

clean:
	-rm -rf *.html
