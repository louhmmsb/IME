(TeX-add-style-hook
 "resumo"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "11pt")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8") ("fontenc" "T1") ("ulem" "normalem") ("xcolor" "hyperref" "x11names") ("babel" "brazilian")))
   (add-to-list 'LaTeX-verbatim-environments-local "minted")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "path")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "url")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "nolinkurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperbaseurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperimage")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperref")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "href")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "path")
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art11"
    "inputenc"
    "fontenc"
    "graphicx"
    "grffile"
    "longtable"
    "wrapfig"
    "rotating"
    "ulem"
    "amsmath"
    "textcomp"
    "amssymb"
    "capt-of"
    "hyperref"
    "minted"
    "xcolor"
    "babel"
    "geometry")
   (LaTeX-add-labels
    "sec:orgfe613b7"
    "sec:org9f7801e"
    "sec:orga89e575"
    "sec:org3ef84b2"
    "sec:org8ae8eaa"
    "sec:orgb813025"
    "sec:orgce3d05e"
    "sec:orgd0824eb"
    "sec:org38756d0"
    "sec:org01723f2"
    "sec:org40c6eb2"
    "sec:org4f2e1d0"
    "sec:org5cbc80f"
    "sec:orgacdf131"
    "sec:org990f2d6"
    "sec:org92f3d6d"
    "sec:org12e6e45"
    "sec:org8925735"
    "sec:org9a7d48c"
    "sec:org9e0b5be"
    "sec:org64ec4a0"))
 :latex)

