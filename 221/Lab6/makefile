NAME = $@



source.wc : source.txt
	wc source.txt > source.wc

.txt.wc:
	wc $<.txt > .wc

clean: 
	rm -f *.wc
	
