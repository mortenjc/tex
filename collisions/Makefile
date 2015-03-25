

quick:
	pdflatex -shell-escape article.tex 

all:
	pdflatex -shell-escape article.tex 
	pdflatex -shell-escape article.tex 	
	bibtex article
	pdflatex -shell-escape article.tex 
	


clean:
	rm -f *.aux *.log article.pdf
