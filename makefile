control:
	$(MAKE) -C src
	$(MAKE) -C doc

.PHONY: clean

clean:
	$(MAKE) -C src clean
	$(MAKE) -C doc clean
