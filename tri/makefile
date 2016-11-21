MID_FILES=tri.ps tri.ctx.dvi tri.ctx.tex
TMP_FILES=tri.ctx.toc tri.ctx.aux tri.ctx.xlg tri.ctx.log cinput.bak tri.ctx.out cinput.tex tri.xlg *.aux *.log *.toc *.out

tri.jpg: tri.ps
	convert  -density 400 $< $@ 

tri.pdf:tri.ps
	ps2pdf $<
tri.ps:tri.dvi
	dvips -o $@ $<

tri.dvi:tri.tex
	latex $< && latex $<


clean:
	rm -rf *.ps *.pdf *.dvi tri $(MID_FILES) $(TMP_FILES) *.jpg
