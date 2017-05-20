control:
	$(MAKE) -C src
	$(MAKE) -C doc
	$(MAKE) -C test

.PHONY: clean

clean:
	$(MAKE) -C src clean
	$(MAKE) -C doc clean
	$(MAKE) -C test clean
