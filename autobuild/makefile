MID_FILES=autobuild.ps autobuild.ctx.dvi autobuild.ctx.tex
TMP_FILES=autobuild.ctx.toc autobuild.ctx.aux autobuild.ctx.xlg autobuild.ctx.log cinput.bak autobuild.ctx.out cinput.tex descent.aux *.toc *.aux *.log *.pdf *.out *.ps *.dvi

pdf:autobuild.ps
	ps2pdf $<

autobuild.ps:autobuild.dvi
	dvips -o $@ $<
autobuild.dvi:autobuild.tex
	latex $< && latex $<

autobuild.ctx.dvi:autobuild.ctx.tex
	latex $< ; latex $<
autobuild.ctx.tex:autobuild.ctx descent.ctx
	cwtex $<
html:autobuild.tex
	latex2html -show_section_numbers -split 0 $<


clean:
	rm $(MID_FILES) $(TMP_FILES) -rf autobuild
