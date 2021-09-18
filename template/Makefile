all:
	make html && make pdf
html:
	pandoc -t html5 -s -t revealjs index.md -o index.html -V theme=simple -V revealjs-url=../_includes/reveal.js 
pdf:
	pandoc index.md -o index.pdf --metadata title=Typeclasses
