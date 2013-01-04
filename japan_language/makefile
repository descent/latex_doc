jl.pdf: jl.ps
	ps2pdf $< 
jl.ps:jl.dvi
	dvips $<
jl.dvi: jl.tex  
	latex $< && latex $<
html: jl.tex
	latex2html $<;
	
clean:
	rm -rf jl.aux  jl.dvi  jl.log  *.pdf *.ps *.log


