MID_FILES=pt.ps pt.ctx.dvi pt.ctx.tex
TMP_FILES=pt.ctx.toc pt.ctx.aux pt.ctx.xlg pt.ctx.log cinput.bak pt.ctx.out cinput.tex pt.xlg *.aux *.log *.toc *.out

pt.pdf:pt.ps
	ps2pdf $<
pt.ps:pt.dvi
	dvips -o $@ $<

pt.dvi:pt.tex
	latex $< && latex $<

pt.ctx.dvi:pt.ctx.tex
	latex $<; latex $<
pt.ctx.tex:pt.ctx descent.ctx
	cwtex $<
html:pt.ctx
	cwtex $<&&latex $<&& latex $<&&cwtex -i $<&& latex2html -show_section_numbers -html_version 4.0 -split 0 $<

pdf: pt.ps
	 ps2pdf $<
clean:
	rm -rf *.ps *.pdf *.dvi pt $(MID_FILES) $(TMP_FILES)
