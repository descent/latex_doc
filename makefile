MID_FILES=*.ps *.dvi freetype.ctx.tex
TMP_FILES=freetype.ctx.toc freetype.ctx.aux freetype.ctx.xlg freetype.ctx.log cinput.bak freetype.ctx.out cinput.tex cnct_cover.aux cnct_cover.tex *.pdf *.toc *.aux *.out *.log

pdf:freetype.ps
	ps2pdf $<
freetype.ps:freetype.dvi
	dvips -o $@ $<

freetype.dvi:freetype.tex
	latex $< && latex $<
freetype.ctx.dvi:freetype.ctx.tex
	latex $< ; latex $<
freetype.ctx.tex:freetype.ctx cnct_cover.ctx
	cwtex $<


clean:
	rm $(MID_FILES) $(TMP_FILES)
