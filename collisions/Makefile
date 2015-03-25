
LATEX = pdflatex -shell-escape
MAIN  = article
TEX   = $(MAIN).tex
PDF   = $(MAIN).pdf

all:
	$(LATEX) $(TEX) 
	bibtex article
	$(LATEX) $(TEX) 
	$(LATEX) $(TEX) 
	open $(PDF) 

view:
	open $(PDF)

clean:
	rm -f *.aux *.log $(PDF) $(MAIN).bbl $(MAIN).blg
