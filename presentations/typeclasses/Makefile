all: index.md 
	make index.html && make index.pdf
index.html: index.md
	pandoc -t html5 -s -t revealjs index.md -o index.html -V theme=simple -V revealjs-url=../_includes/reveal.js --metadata title="Typeclasses"
index.pdf: index.md
	pandoc index.md -o index.pdf --metadata title="Typeclasses"
clean:
	rm index.html index.pdf

