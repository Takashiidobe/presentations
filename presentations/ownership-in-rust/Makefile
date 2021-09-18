all: index.md 
	make index.html && make index.pdf
index.html: index.md
	pandoc -t html5 -s -t revealjs index.md -o index.html -V theme=simple -V revealjs-url=../_includes/reveal.js --metadata title="Ownership in Rust"
index.pdf: index.md
	pandoc index.md -o index.pdf --metadata title="Ownership in Rust"
clean:
	rm index.html index.pdf
