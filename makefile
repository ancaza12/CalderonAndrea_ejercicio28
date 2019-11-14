friccion.png : pre28.dat pre28.py
	python pre28.py
    
pre28.dat : pre28.x
	./pre28.x > pre28.dat

pre28.x : pre28.cpp
	c++ pre28.cpp -o pre28.x

clean:
	rm -rf pre28.x pre28.dat friccion.png