MID_FILES=stack_smashing.ps stack_smashing.ctx.dvi stack_smashing.ctx.tex
TMP_FILES=stack_smashing.ctx.toc stack_smashing.ctx.aux stack_smashing.ctx.xlg stack_smashing.ctx.log cinput.bak stack_smashing.ctx.out cinput.tex stack_smashing.xlg *.aux *.log *.toc *.out

fat12_bl.pdf: fat12_bl.tex
	 pdflatex $< && pdflatex $<
clean:
	rm -rf *.ps *.pdf *.dvi stack_smashing $(MID_FILES) $(TMP_FILES)
