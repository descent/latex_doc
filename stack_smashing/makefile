MID_FILES=stack_smashing.ps stack_smashing.ctx.dvi stack_smashing.ctx.tex
TMP_FILES=stack_smashing.ctx.toc stack_smashing.ctx.aux stack_smashing.ctx.xlg stack_smashing.ctx.log cinput.bak stack_smashing.ctx.out cinput.tex stack_smashing.xlg *.aux *.log *.toc *.out

stack_smashing.pdf:stack_smashing.ps
	ps2pdf $<
stack_smashing.ps:stack_smashing.dvi
	dvips -o $@ $<

stack_smashing.dvi:stack_smashing.tex
	latex $< && latex $<

stack_smashing.ctx.dvi:stack_smashing.ctx.tex
	latex $<; latex $<
stack_smashing.ctx.tex:stack_smashing.ctx descent.ctx
	cwtex $<
html:stack_smashing.ctx
	cwtex $<&&latex $<&& latex $<&&cwtex -i $<&& latex2html -show_section_numbers -html_version 4.0 -split 0 $<

pdf: stack_smashing.ps
	 ps2pdf $<
clean:
	rm -rf *.ps *.pdf *.dvi stack_smashing $(MID_FILES) $(TMP_FILES)
