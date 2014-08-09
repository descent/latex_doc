MID_FILES=the_roots_of_lisp_chinese.ps the_roots_of_lisp_chinese.ctx.dvi the_roots_of_lisp_chinese.ctx.tex
TMP_FILES=the_roots_of_lisp_chinese.ctx.toc the_roots_of_lisp_chinese.ctx.aux the_roots_of_lisp_chinese.ctx.xlg the_roots_of_lisp_chinese.ctx.log cinput.bak the_roots_of_lisp_chinese.ctx.out cinput.tex descent.aux *.toc *.aux *.log *.pdf *.out *.ps *.dvi

pdf:the_roots_of_lisp_chinese.ps
	ps2pdf $<

the_roots_of_lisp_chinese.ps:the_roots_of_lisp_chinese.dvi
	dvips -o $@ $<
the_roots_of_lisp_chinese.dvi:the_roots_of_lisp_chinese.tex
	latex $< && latex $<

the_roots_of_lisp_chinese.ctx.dvi:the_roots_of_lisp_chinese.ctx.tex
	latex $< ; latex $<
the_roots_of_lisp_chinese.ctx.tex:the_roots_of_lisp_chinese.ctx descent.ctx
	cwtex $<
html:the_roots_of_lisp_chinese.tex
	latex2html -show_section_numbers -split 0 $<


clean:
	rm $(MID_FILES) $(TMP_FILES) -rf the_roots_of_lisp_chinese
