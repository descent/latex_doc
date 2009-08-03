MID_FILES=ipaq.ps ipaq.ctx.dvi ipaq.ctx.tex
TMP_FILES=ipaq.ctx.toc ipaq.ctx.aux ipaq.ctx.xlg ipaq.ctx.log cinput.bak ipaq.ctx.out cinput.tex ipaq.xlg *.aux *.log *.toc *.out

ipaq.pdf:ipaq.ps
	ps2pdf $<
ipaq.ps:ipaq.dvi
	dvips -o $@ $<

ipaq.dvi:ipaq.tex
	latex $< && latex $<

ipaq.ctx.dvi:ipaq.ctx.tex
	latex $<; latex $<
ipaq.ctx.tex:ipaq.ctx descent.ctx
	cwtex $<
html:ipaq.ctx
	cwtex $<&&latex $<&& latex $<&&cwtex -i $<&& latex2html -show_section_numbers -html_version 4.0 -split 0 $<

pdf: ipaq.ps
	 ps2pdf $<
clean:
	rm -rf *.ps *.pdf *.dvi ipaq $(MID_FILES) $(TMP_FILES)
