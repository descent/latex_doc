MID_FILES=coroutines_in_c.ps coroutines_in_c.ctx.dvi coroutines_in_c.ctx.tex
TMP_FILES=coroutines_in_c.ctx.toc coroutines_in_c.ctx.aux coroutines_in_c.ctx.xlg coroutines_in_c.ctx.log cinput.bak coroutines_in_c.ctx.out cinput.tex coroutines_in_c.xlg *.aux *.log *.toc *.out

coroutines_in_c.pdf:coroutines_in_c.ps
	ps2pdf $<
coroutines_in_c.ps:coroutines_in_c.dvi
	dvips -o $@ $<

coroutines_in_c.dvi:coroutines_in_c.tex
	latex $< && latex $<

coroutines_in_c.ctx.dvi:coroutines_in_c.ctx.tex
	latex $<; latex $<
coroutines_in_c.ctx.tex:coroutines_in_c.ctx descent.ctx
	cwtex $<
html:coroutines_in_c.ctx
	cwtex $<&&latex $<&& latex $<&&cwtex -i $<&& latex2html -show_section_numbers -html_version 4.0 -split 0 $<

pdf: coroutines_in_c.ps
	 ps2pdf $<
clean:
	rm -rf *.ps *.pdf *.dvi coroutines_in_c $(MID_FILES) $(TMP_FILES)
