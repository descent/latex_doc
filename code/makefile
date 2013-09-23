MID_FILES=
TMP_FILES=*.xlg *.aux *.log *.toc *.out

all: code.pdf

%.pdf:%.tex
	pdflatex $< && pdflatex $<
%.dvi:%.tex
	latex $< && latex $<


#pdf: stack_smashing.ps
#	 ps2pdf $<
clean:
	rm -rf *.ps *.pdf *.dvi $(MID_FILES) $(TMP_FILES)
