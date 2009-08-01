MID_FILES=autobuild.ps autobuild.ctx.dvi autobuild.ctx.tex
TMP_FILES=autobuild.ctx.toc autobuild.ctx.aux autobuild.ctx.xlg autobuild.ctx.log cinput.bak autobuild.ctx.out cinput.tex descent.aux descent.tex

autobuild.ps:autobuild.ctx.dvi
	dvips -o $@ $<

autobuild.ctx.dvi:autobuild.ctx.tex
	latex $< ; latex $<
autobuild.ctx.tex:autobuild.ctx descent.ctx
	cwtex $<
html:autobuild.ctx
	latex2html -show_section_numbers -split 0 autobuild.ctx

pdf:autobuild.ps
	ps2pdf $<

clean:
	rm $(MID_FILES) $(TMP_FILES) -rf autobuild
