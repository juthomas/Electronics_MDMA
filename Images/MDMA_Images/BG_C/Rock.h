/* GIMP RGBA C-Source image dump (Rock.c) */

static struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[80 * 60 * 2 + 1];
} gimp_image = {
  80, 60, 2,
  "\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*f\001f\001f\001f\001f\001f\001f\001f\001f\001"
  "f\001f\001f\001\203\031\203\031\203\031\203\031\203\031\203\031\203\031\203\031\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*f\001f\001f\001f\001"
  "f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*f\001f\001f\001f\001"
  "f\001f\001f\001f\001f\001f\001\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*f\001f\001\203\031\005\234\005\234C\202fjfjfj\203\031"
  "\203\031\203\031\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000f\001f\001\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*f"
  "\001f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001f\001\203\031\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*f\001f\001\250R\200\244\200\244\200\244\200\244"
  "\200\244\200\244\200\244\200\244\200\244\200\244\200\244\200\244\200\244"
  "\005\234\200\244C\202\203\000f\001f\001\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*f\001f\001f\001\203\000\203\000\203\000\203\000\203\000\203"
  "\000\203\000f\001f\001f\001f\001f\001f\001f\001f\001f\001\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*f\001f\001\250R\200\244\200\244\200\244\200\244\200\244\200\244\200\244"
  "\200\244\200\244\200\244\200\244\200\244\200\244\200\244\200\244\005\234\203"
  "\000f\001f\001\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*f\001f\001f\001\200\244\200\244\200\244\200\244\005\234\005\234$[$[\005\234"
  "\005\234\005\234C\202fjfjf\001f\001\206*\206*\206*\206*\206*\206*\206*\206*\206*"
  "\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*f\001f\001\250R\200\244\200\244\200\244\200\244\200\244\200\244\200\244\200"
  "\244\200\244\200\244\200\244\200\244\200\244\200\244\200\244\005\234\203\000"
  "f\001f\001\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*f\001f\001f\001\200\244\200\244\200\244\200\244\200\244\200\244\200\244\200"
  "\244\200\244\200\244\200\244\200\244\200\244fjf\001f\001\206*\206*\206*\206*"
  "\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*f\001f\001\250R\200\244\200\244\200\244\200\244\200"
  "\244\200\244\200\244\200\244\200\244\200\244\200\244\200\244\200\244\200"
  "\244\200\244\005\234\203\000f\001f\001\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*f\001f\001f\001\200\244\200\244\200\244\200\244"
  "\200\244\200\244\200\244\200\244\200\244\200\244\200\244\200\244\200\244"
  "fjf\001f\001\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*f\001f\001\250R\200\244"
  "\200\244\200\244\200\244\200\244\200\244\200\244\200\244\200\244\200\244"
  "\200\244\200\244\200\244\200\244\200\244\005\234\203\000f\001f\001\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\346c\346c\346c\346c\346c\346cf\001f\001f\001\200"
  "\244\200\244\200\244\200\244\200\244\200\244\200\244\200\244\200\244\200"
  "\244\200\244\200\244\200\244fjf\001f\001\206*S\235\032\327\032\327\250R\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*f\001f\001\250R\200\244\200\244\200\244\200\244\200\244\200\244\200"
  "\244\200\244\200\244\200\244\200\244\200\244\250R\206*\206*\206*\206*\206"
  "*\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\206*f\001f\001f\001\200\244\200\244\200\244\200\244\200\244\200\244\200\244\200"
  "\244\200\244\200\244\200\244\200\244\200\244fjf\001\250R\032\327S\235S\235S"
  "\235\032\327S\235\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*f\001f\001\250R\200\244\005\234\200\244\200\244"
  "\005\234\200\244\200\244\200\244\200\244\005\234$[\314\234$[\346c\346c\346c\346"
  "c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\346c\206*f\001f\001f\001\200\244\200\244\200\244\200\244\200\244\200\244\200"
  "\244\200\244\200\244\200\244\200\244\200\244\200\244fjf\001S\235S\235\250R"
  "\206*\206*\250R\032\327\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*"
  "\206*\206*\206*\206*\206*\206*\206*\206*f\001f\001\250R\200\244\200\244\200\244"
  "\200\244\200\244\200\244\200\244\200\244\250R\354\243R\306\314\234\346c\346"
  "c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\346c\346c\346c\346c\206*f\001f\001f\001\200\244C\202\200\244\200\244\005\234\200"
  "\244\200\244\200\244\200\244\005\234\200\244\200\244C\202fj\354\243S\235\250"
  "R\206*\206*\206*\206*\354\243\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*f\001f\001f\001C\202\200\244C\202"
  "\005\234\200\244fj$[\314\234R\306R\306\314\234\346c\346c\346c\346c\346c\346"
  "c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\206*\206*f\001f\001f\001C\202\200\244C\202\005\234\200\244C\202\005\234\005\234C\202"
  "\200\244\005\234C\202\200\244fjS\235S\235\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*f\001f\001f\001\005\234\200\244\005\234\200\244\206*\354\243R\306R\306R"
  "\306\314\234\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c"
  "\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\206*\206*f\001f\001f\001\005\234"
  "\200\244\005\234\200\244\200\244C\202\200\244\200\244C\202\200\244\200\244"
  "\005\234\200\244fjS\235\032\327\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*f\001f\001\250R\200\244C\202\200\244\206*\314\234R\306R\306R\306\314\234\346"
  "c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\346c\346c\346c\346c\346c\346c$[\206*\206*f\001f\001f\001\200\244C\202\200\244"
  "\005\234C\202\200\244\005\234\005\234\200\244C\202\005\234\200\244C\202fjS\235\032"
  "\327\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*f\001f\001\250R\200\244C\202"
  "\200\244\206*\346cR\306R\306\314\234\346c\346c\346c\346c\346c\346c\346c\346"
  "c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\206*\206*\206*f\001f\001f\001\200\244C\202\200\244\200\244\005\234\200\244\200"
  "\244\200\244\200\244\005\234\200\244\200\244C\202fjS\235\032\327\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*f\001f\001\250RC\202C\202\005\234\206*\346c\346"
  "c\314\234\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\206*S\235S\235\250"
  "Rf\001f\001\005\234\005\234C\202C\202\005\234\005\234C\202C\202\005\234C\202C\202C\202"
  "\005\234fjS\235\032\327\206*\206*\206*\206*\206*S\235\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*f\001f\001"
  "f\001C\202\200\244fj\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\346c\346c\346cS\235\032\327S\235S\235f\001C\202C\202C\202C\202C\202C\202C"
  "\202C\202C\202C\202C\202C\202C\202fjS\235\032\327\250R\206*\206*\250RS\235"
  "S\235\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*f\001f\001\250R\005\234\005\234$[\346c\346c\346c\346c\346c\346"
  "c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\346c\346c\346c\346c\346c\346c\346c\206*\206*\206*\354\243\032\327\032\327"
  "\354\243\005\234\005\234\005\234C\202\005\234C\202C\202\005\234\005\234\005\234\005\234\005"
  "\234fjS\235\032\327\032\327\032\327\032\327S\235S\235\354\243\206*\206*\206*"
  "\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*f\001f\001f\001$[$[\250R\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\346c\346c\206*\206*\206*f\001\250R\032\327\032\327fj$[$[fjfj\203\000f\001f\001f\001"
  "f\001f\001f\001\203\031S\235S\235\250R\250R\250R\250R\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*f"
  "\001f\001f\001f\001f\001\203\031\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\346c\346c\206*\206*\206*f\001f\001\206*\032\327\032\327\250Rf\001f\001f\001f\001f\001f"
  "\001f\001f\001f\001f\001\203\031S\235S\235\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*f\001f\001f\001f\001\206*\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\346c\346c\346c\206*\206*\206*\206*f\001f\001\250R\032\327\032\327f\001f\001f\001f\001"
  "f\001\206*\206*\206*\206*\206*\203\031S\235S\235\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*$[\346c\346c\346c\346c\346c\346"
  "c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346"
  "c\346c\346c\346c\346c\346c\354\243$[\206*\206*\206*\206*\206*\206*\206*S"
  "\235\032\327\032\327\250R\206*\206*\206*\206*\206*\206*\206*\206*\203\031S\235"
  "S\235\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*fj"
  "fj\354\243\354\243\354\243fjfjfj\206*\206*\206*\206*\206*\206*\206*\206*"
  "$[\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\346c\354\243$[\346c"
  "\314\234\314\234$[\346c\354\243\354\243\314\234\314\234\354\243\314\234\314"
  "\234\354\243\354\243\354\243\206*\206*\206*\206*\206*\206*\250RS\235S\235"
  "\032\327\032\327\250R\206*\206*\206*\206*\206*\206*\206*\203\031S\235S\235\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*C\202\354\243\354\243"
  "\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243C\202\250"
  "R\206*\206*\206*\206*\206*$[\346c\346c\346c\314\234$[\354\243\354\243$[\314"
  "\234\354\243\314\234\346c\354\243\354\243\314\234$[\354\243\354\243$[\354"
  "\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243\346"
  "c\206*\206*\206*\206*\206*S\235S\235fj\206*\032\327\032\327\206*\206*\206*"
  "\206*\206*\206*\206*\203\031S\235S\235\206*\206*\206*\206*\206*\206*\206*"
  "\206*\203\031\250R\354\243\354\243\354\243\354\243\354\243\354\243\354\243"
  "\314\234\314\234\314\234\354\243\354\243\354\243\354\243\354\243fjfj\206"
  "*\206*\250R\314\234\314\234\354\243\314\234\314\234\354\243\354\243\354\243"
  "\354\243\354\243\354\243\354\243\354\243\354\243\354\243\314\234\354\243"
  "\354\243\314\234\354\243\354\243\314\234\314\234\314\234\314\234\314\234"
  "\314\234\314\234\250RS\235S\235\032\327\032\327S\235S\235S\235f\001f\001\250R\032"
  "\327\032\327\250Rf\001f\001f\001f\001f\001\203\031S\235S\235f\001f\001f\001f\001f\001f\001\206*\203"
  "\031\206*\250R\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354"
  "\243\354\243\354\243R\306\354\243\354\243R\306\354\243\354\243\354\243fj"
  "f\001\206*\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243"
  "\354\243R\306\314\234\354\243\314\234R\306\354\243\354\243R\306R\306\354"
  "\243\354\243R\306\314\234R\306R\306R\306R\306R\306R\306\250R\250RS\235S\235"
  "S\235\354\243\203\031f\001f\001f\001f\001\206*\032\327\032\327f\001f\001f\001f\001f\001\203\031"
  "S\235S\235f\001f\001f\001f\001f\001f\001f\001\206*fj\206*\354\243\354\243\354\243\354\243"
  "\354\243\354\243\354\243\314\234\354\243R\306R\306\314\234\354\243\354\243"
  "\314\234\354\243\354\243\354\243fj\354\243\354\243\314\234\314\234\314\234"
  "\314\234\314\234\314\234\314\234\314\234\314\234R\306R\306R\306\314\234R"
  "\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306\314"
  "\234\203\000\203\031\203\031\203\031\203\031f\001f\001\203\000\203\000\203\000\203\000\250"
  "R\032\327\032\327\250R\203\000\203\000\203\000\203\031S\235S\235\203\000\203\000\203\000"
  "\203\000\203\000\203\000\206*\206*\354\243\354\243\354\243\354\243\354\243\354"
  "\243\354\243\354\243\354\243\354\243\354\243R\306R\306\354\243\354\243R\306"
  "R\306\354\243\354\243\354\243\354\243\354\243R\306\314\234\354\243R\306R"
  "\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306"
  "R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306f\001f\001\203\000f\001f\001\203"
  "\000f\001\203\000f\001f\001\203\000f\001\206*\032\327\032\327f\001\203\000f\001\203\031S\235S\235"
  "\203\000f\001\203\000f\001\203\000f\001\206*\206*\354\243\354\243\354\243\354\243\354"
  "\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243R\306\314\234"
  "\314\234R\306\354\243\314\234R\306\354\243\354\243\354\243\354\243R\306R"
  "\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306"
  "R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306\314\234f\001\203"
  "\000f\001f\001\203\000f\001\203\000f\001f\001\203\000f\001f\001\250R\032\327\032\327\250Rf\001\250"
  "R\354\243fj\203\000f\001\203\000f\001\203\000f\001\206*\206*\206*fj\354\243\354\243\354"
  "\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243\314\234R\306"
  "R\306\354\243\354\243\354\243R\306\354\243\354\243\354\243\354\243\314\234"
  "R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306"
  "R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306\206*\203"
  "\000f\001f\001\203\000f\001\203\000f\001f\001\203\000f\001f\001\203\000\250R\032\327\032\327\032\327"
  "\032\327S\235\250R\203\000f\001\203\000f\001\203\000f\001\206*\206*\250R\250R\354\243"
  "\354\243\354\243\250R\354\243\354\243\354\243\354\243\354\243\354\243\354"
  "\243R\306R\306R\306\354\243R\306R\306R\306R\306\354\243\354\243\354\243R"
  "\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306"
  "R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306\314\234"
  "\203\000f\001f\001\203\000f\001\203\000f\001f\001\203\000f\001f\001\203\000f\001\206*S\235S\235S\235"
  "S\235S\235\203\031f\001\203\000f\001\203\000f\001\206*\250R\354\243fj\354\243\354\243"
  "\354\243\250R\354\243\354\243\354\243\354\243\314\234\354\243\354\243\354"
  "\243R\306\354\243\354\243R\306R\306\314\234\354\243\354\243\354\243\354\243"
  "\354\243R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306"
  "R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306"
  "\203\000f\001f\001\203\000f\001\203\000f\001f\001\203\000f\001f\001\203\000f\001f\001\250RS\235S\235"
  "\032\327S\235S\235f\001\203\000f\001\203\000f\001\206*fj\354\243\354\243\354\243\354"
  "\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243R\306\354\243"
  "\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243"
  "\354\243\354\243\354\243R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306"
  "R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306"
  "R\306R\306R\306\203\031f\001f\001\203\000f\001\203\000f\001f\001\203\000f\001f\001\203\000f\001f\001"
  "\203\000\206*S\235\314\234S\235\032\327S\235f\001f\001\203\000f\001\206*\250R\354\243"
  "\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243"
  "\354\243\354\243\354\243\354\243\354\243\314\234R\306\354\243\354\243\354"
  "\243\354\243R\306R\306\354\243\354\243\354\243R\306R\306R\306R\306R\306R"
  "\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306"
  "R\306R\306R\306R\306R\306R\306R\306\346cf\001f\001\203\000f\001\203\000f\001\032\327\032"
  "\327\032\327\032\327\314\234\203\000\203\000\203\031\206*\250R\314\234\314\234S"
  "\235\032\327S\235f\001\203\000f\001\206*\206*\206*\354\243\354\243\354\243\206*"
  "\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243"
  "\354\243\354\243R\306\354\243\354\243\354\243\354\243\354\243\354\243\354"
  "\243\354\243\354\243R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306"
  "R\306R\306R\306R\306R\306R\306R\306\032\327\032\327\032\327\032\327R\306R\306"
  "R\306R\306R\306R\306f\001f\001\203\000f\001\203\000\032\327\346c$[f\001\250R\250R\250"
  "R\250R\032\327\250R\203\031\346c\314\234\354\243\354\243\032\327S\235f\001f\001"
  "\206*\206*fj\354\243\354\243\206*\206*\250R\354\243\354\243\354\243\354\243"
  "\354\243\354\243\354\243\314\234\354\243\354\243\354\243\354\243\354\243"
  "\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243R\306R\306"
  "R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306"
  "\314\234R\306R\306R\306\032\327\032\327\032\327\032\327R\306R\306\206*f\001\203"
  "\000f\001\203\000\314\234\314\234\250R\250RS\235S\235\032\327\032\327\032\327\032\327"
  "S\235\203\031fj\354\243\354\243\354\243\032\327S\235f\001\206*fj\354\243\354"
  "\243\354\243\354\243\206*\354\243\354\243\354\243\354\243\354\243\354\243"
  "\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243"
  "\354\243\354\243\354\243\354\243\354\243\354\243\354\243R\306R\306R\306R"
  "\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306\032\327\032\327"
  "\346cR\306R\306R\306R\306\032\327\032\327S\235\032\327R\306\206*f\001\203\000f\001"
  "\203\000R\306\346c$[f\001f\001\203\031\032\327\032\327\032\327R\306\032\327\250R\206"
  "*\354\243\354\243\354\243\354\243\032\327S\235\206*\206*\206*\354\243\354"
  "\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354"
  "\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354"
  "\243\354\243\354\243\354\243\354\243\354\243\354\243R\306R\306R\306R\306"
  "R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306\032\327R\306\314\234"
  "R\306R\306R\306R\306\032\327\032\327R\306\032\327R\306\250Rf\001\203\000f\001\203"
  "\000R\306\346c$[f\001f\001\203\031\032\327\032\327\032\327\354\243\032\327\354\243\250"
  "R\203\000fj\354\243\354\243\354\243\032\327\206*\206*\206*\206*\206*\250R\354"
  "\243\354\243\354\243\354\243\032\327\032\327\032\327\032\327\314\234\354\243"
  "\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243"
  "\354\243\354\243\354\243\354\243\354\243R\306R\306R\306R\306R\306R\306R\306"
  "R\306R\306R\306R\306R\306R\306R\306\032\327\032\327R\306R\306R\306R\306R\306"
  "\032\327\032\327R\306\032\327R\306\314\234f\001\203\000f\001\203\000R\306\346c$[f\001"
  "f\001\203\031\032\327\032\327\032\327\354\243\032\327\354\243fj\203\000f\001\354\243"
  "\354\243\354\243\354\243\206*\206*\206*\206*\203\000\206*\354\243\354\243\354"
  "\243\032\327\314\234\354\243\354\243S\235S\235S\235S\235\032\327\354\243\354"
  "\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354\243\354"
  "\243\354\243R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306"
  "R\306R\306\032\327\032\327\032\327\032\327\032\327\032\327\032\327\032\327\032\327"
  "\032\327\032\327R\306\314\234f\001\203\000f\001\203\000\032\327R\306R\306R\306R\306"
  "R\306\032\327\032\327\032\327\354\243\032\327\354\243fj\203\000f\001\203\000fj\354"
  "\243\354\243\206*\206*\206*\206*f\001f\001\354\243\354\243\032\327R\306\005\234"
  "\354\243\354\243\354\243\354\243\032\327\032\327\032\327\354\243\354\243\250"
  "R\206*\206*\354\243\354\243\354\243\354\243\354\243\354\243\314\234R\306"
  "R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306R\306\032\327"
  "R\306\314\234\314\234\314\234\314\234\314\234R\306\032\327R\306S\235R\306"
  "\250Rf\001\203\000f\001\203\000R\306\032\327\032\327\032\327\032\327\032\327\032\327\032"
  "\327\032\327\354\243\032\327\354\243fj\203\000f\001\203\000f\001\354\243\354\243\206"
  "*\206*\250R\250R\206*\206*fjR\306R\306R\306\005\234\354\243\354\243\354\243"
  "\354\243\032\327\032\327\032\327\354\243\354\243\206*\206*\206*\250R\354\243"
  "\206*\206*\354\243\354\243\314\234R\306R\306R\306R\306R\306R\306R\306R\306"
  "R\306R\306R\306R\306R\306R\306\032\327R\306\200\244\200\244\200\244\200\244"
  "\200\244R\306\032\327R\306\032\327\354\243\354\243f\001\203\000f\001\203\000R\306\200"
  "\244\200\244\200\244\200\244\200\244\032\327\032\327\032\327\354\243\032\327"
  "\354\243fjfj\250Rfj\250Rfj\354\243\206*\250R\354\243\354\243\354\243\206"
  "*\206*R\306S\235R\306\005\234\354\243\354\243\354\243\354\243\032\327\032\327"
  "\032\327\354\243\354\243\206*\206*\354\243\250R\206*\206*\203\031\206*\206"
  "*\314\234R\306R\306R\306\354\243R\306R\306R\306\354\243\314\234R\306\354"
  "\243\354\243R\306R\306R\306R\306\200\244\200\244\200\244\200\244\200\244"
  "R\306\032\327R\306S\235\354\243\250Rf\001\203\000f\001\203\000R\306\200\244\200\244"
  "\200\244\200\244\200\244\032\327\032\327\032\327R\306\314\234C\202C\202C\202"
  "C\202C\202C\202C\202C\202f\001\206*\354\243\354\243\354\243\354\243\206*R\306"
  "S\235R\306\005\234\354\243\354\243\206*\206*\032\327\032\327\032\327\354\243\250"
  "R\206*fj\354\243\354\243\206*\203\000\203\000\203\031\206*R\306R\306\354\243\354"
  "\243R\306\314\234\354\243\314\234R\306\354\243\354\243\354\243\354\243\354"
  "\243\354\243R\306R\306\200\244\200\244\200\244\200\244\200\244R\306\032\327"
  "R\306S\235C\202C\202C\202C\202C\202C\202R\306\200\244\200\244\200\244\200"
  "\244\200\244\032\327\032\327\032\327C\202C\202C\202C\202C\202C\202C\202C\202"
  "C\202C\202\203\000\203\031\206*\354\243\354\243\250R\206*R\306S\235R\306\005\234"
  "\250R\250R\206*\206*\032\327\032\327\032\327\203\031f\001\206*\206*\250R\250R\206"
  "*\203\000\203\000\206*\354\243\354\243\354\243\354\243\354\243\314\234\354\243"
  "\354\243\354\243\314\234C\202C\202C\202C\202fjfjfj\314\234\200\244\200\244"
  "\200\244\200\244\200\244R\306\032\327R\306S\235C\202C\202C\202C\202C\202C"
  "\202R\306\200\244$[$[$[$[R\306R\306\032\327C\202C\202C\202C\202C\202C\202"
  "C\202C\202C\202C\202\206*\206*\206*\206*\206*\206*\206*R\306S\235R\306\005"
  "\234\250R\250R\250R\250R\032\327\032\327\032\327\203\000\203\000\203\000\206*\250"
  "R\250Rfj\203\031\206*$[\346cC\202C\202C\202C\202C\202C\202C\202C\202C\202"
  "C\202C\202C\202C\202C\202C\202C\202\314\234\200\244fj\203\031$[\250R\314\234"
  "R\306R\306S\235C\202C\202C\202C\202C\202C\202C\202\314\234C\202C\202\200"
  "\244R\306\032\327\032\327\314\234C\202C\202C\202C\202C\202C\202C\202C\202C"
  "\202C\202\206*\206*\203\031\203\000\203\000f\001\206*R\306\314\234\032\327R\306R"
  "\306R\306R\306R\306\032\327\032\327\032\327fjfjfjfjC\202C\202C\202C\202C\202"
  "C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202"
  "C\202C\202C\202C\202\314\234C\202C\202\005\234\354\243\354\243S\235\354\243"
  "C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202"
  "C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202\206*\203\031f\001\203"
  "\031\206*C\202C\202\354\243R\306R\306\032\327\032\327\032\327\032\327\032\327\032"
  "\327\032\327\032\327C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202"
  "C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202"
  "C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202"
  "C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202\206*\206"
  "*\206*\206*\206*\206*\206*\206*C\202C\202C\202C\202C\202C\202C\202C\202C"
  "\202R\306\200\244\200\244\200\244\200\244\200\244\032\327\032\327\032\327C\202"
  "C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202"
  "C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202"
  "C\202C\202C\202C\202C\202C\202C\202fjfjfjfjfjfjfjfj\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*C\202C\202C\202C"
  "\202C\202C\202C\202C\202C\202R\306\005\234\203\031\203\031\203\031\203\031R\306"
  "R\306\032\327C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202"
  "C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202"
  "C\202C\202\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*f\001f\001f\001\203\000\203"
  "\000\203\000\203\000\203\000\203\000C\202C\202C\202C\202C\202C\202C\202C\202C\202C"
  "\202\354\243C\202\005\234\005\234\314\234\032\327S\235\354\243C\202C\202C\202"
  "C\202C\202C\202C\202C\202C\202C\202C\202C\202fjfjfjfjfjfjfjfj\250R\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\206*\203\031\203\031\203\031\203\031\203\031\203\000\203\000\203\000\203\000\203"
  "\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203"
  "\000C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202"
  "C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202\250R\206*\206*\206*\206"
  "*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206*\206"
  "*\206*\203\031f\001f\001f\001\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203"
  "\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203"
  "\000f\001f\001f\001\203\000f\001\206*\206*\206*\206*\206*C\202C\202C\202C\202C\202C\202"
  "C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202"
  "C\202C\202C\202C\202fj\250R\250R\206*\206*\206*\206*\206*\206*\206*\206*"
  "\206*f\001\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203"
  "\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\031\203\031\203"
  "\031\203\031f\001f\001f\001f\001\203\031\206*\206*\206*\206*\206*\206*\203\031\206*\206"
  "*\206*\206*\206*\206*\250RC\202C\202C\202C\202C\202C\202C\202C\202C\202C"
  "\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202"
  "C\202C\202C\202C\202\206*\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000"
  "\203\000\203\000\203\000\203\000\203\000\203\000\203\000\203\000f\001f\001f\001\206*\206*\203\031"
  "\206*\206*\206*\206*\206*\206*\203\031\206*\206*\206*\206*\206*\206*\206*"
  "\203\031\206*\206*\206*\206*\206*\206*\203\031\206*\206*\206*\206*\206*\206"
  "*f\001\206*fjC\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C"
  "\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202"
  "C\202\250Rfjfj\203\031\203\031\203\000f\001f\001f\001\203\031\206*\206*\203\031\206*"
  "\206*\206*\206*\206*\206*\206*\203\031\206*\206*\206*\206*\206*\206*\203\031"
  "\206*\206*\206*\206*\206*\206*\206*\203\031\206*\206*\206*\206*\206*\206*"
  "\203\031\206*\206*\206*\206*\206*\206*f\001f\001f\001\203\031\250RC\202C\202C\202"
  "C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202"
  "C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202C\202fjfj\203\031\206*\206"
  "*\206*\206*\206*\206*\203\031\206*\206*\206*\206*\206*\206*\206*\203\031\206"
  "*\206*\206*\206*\206*\206*\203\031\206*\206*\206*\206*\206*\206*\206*\203"
  "\031\206*\206*\206*\206*\206*\206*\203\031\206*\206*\206*\206*\206*\206*",
};

