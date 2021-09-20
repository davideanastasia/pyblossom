clean:
	rm -fr .pytest_cache/
	rm -fr pyblossom.egg-info/
	rm -fr build/
	find . -type d -name __pycache__ -exec rm -r {} \+
	find . -type f -name *.so -exec rm -r {} \+

build_ext:
	python3 setup.py build_ext -i

develop:
	sudo python3 setup.py develop

test: build_ext
	pytest -v