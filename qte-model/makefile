MID_FILES=qte-model.ps qte-model.ctx.dvi qte-model.ctx.tex
TMP_FILES=qte-model.ctx.toc qte-model.ctx.aux qte-model.ctx.xlg qte-model.ctx.log cinput.bak qte-model.ctx.out cinput.tex 

CTXS=qte-model.ctx qte-key-handler.ctx qte-keyevent.ctx qte-connect-server.ctx qte-eventloop.ctx qpopupmenu_by_key.ctx

qte-model.ps:qte-model.ctx.dvi
	dvips -o $@ $<

qte-model.ctx.dvi:qte-model.ctx.tex 
	latex $< ; latex $<
qte-model.ctx.tex:${CTXS}
	cwtex $<

pdf:qte-model.ps
	ps2pdf $<
qte-model:qte-model.ctx
	cwtex $<&&latex $<&& latex $<&&cwtex -i $<&& latex2html -html_version 4.0 $<

html:qte-model.ctx
	 #latex2html -show_section_numbers -split 0 $<
	 latex2html -show_section_numbers $<
clean:
	rm $(MID_FILES) $(TMP_FILES) *.aux *.pdf *.dvi -rf qte-model
