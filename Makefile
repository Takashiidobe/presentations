all:
	bin/build
new:
	bin/new $(name)
deploy:
	make && ntl deploy --prod