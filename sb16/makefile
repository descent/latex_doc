MID_FILES=
TMP_FILES=*.xlg *.aux *.log *.toc *.out

all: sb16.pdf

#%.pdf:%.tex
#	pdflatex $< && pdflatex $<

sb16.pdf: c10.asm
%.pdf:%.ps
	ps2pdf $<

%.ps:%.dvi
	dvips $<
%.dvi:%.tex
	latex $< && latex $<

html:stack_smashing.ctx
	cwtex $<&&latex $<&& latex $<&&cwtex -i $<&& latex2html -show_section_numbers -html_version 4.0 -split 0 $<

#pdf: stack_smashing.ps
#	 ps2pdf $<
clean:
	rm -rf *.ps *.pdf *.dvi $(MID_FILES) $(TMP_FILES)
