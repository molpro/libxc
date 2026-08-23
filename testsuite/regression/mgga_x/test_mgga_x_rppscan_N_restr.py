
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_rppscan_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rppscan", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.884522993570063e+00, -4.785633551287898e+00, -4.647023903785342e+00, -4.454926408033584e+00, -4.192978900174277e+00, -3.843935670247515e+00, -3.393791304323813e+00, -2.839225678222145e+00, -2.197509758910804e+00, -1.506029512919862e+00, -8.389583181019971e-01, -5.691241963649321e-01, -5.788513001735076e-01, -4.939473845434506e-01, -3.337865694199614e-01, -1.757502124321392e-01, -6.635785975425094e-02, -1.692331280644105e-02, -2.226551708377708e-03, -1.021847466828020e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_rppscan_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rppscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.410741281740189e+00, -6.277696465747096e+00, -6.091176600870211e+00, -5.832605049049127e+00, -5.479849969524338e+00, -5.009448405357904e+00, -4.401949018647824e+00, -3.651177087209901e+00, -2.773290849381412e+00, -1.788381620297613e+00, -1.137093881154906e+00, -7.845456428839547e-01, -8.656528565529615e-01, -6.630139753040817e-01, -4.155412796655453e-01, -1.707444366705554e-01, -6.149602434307349e-02, -2.494216320043036e-02, -3.744399323329855e-03, -1.556497352235811e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rppscan_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rppscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.138432585616958e-06, -3.390894039449579e-06, -3.789140157182710e-06, -4.443189672198791e-06, -5.581434987144237e-06, -7.735145325854582e-06, -1.234029130603833e-05, -2.420039166130981e-05, -6.627548221761161e-05, -3.566055540647814e-04, -7.191419718199943e-04, -5.693729018453669e-03, -2.346630824710091e-02, -4.058636618616206e-02, -1.607770347073234e-01, -1.382854677001503e+00, -7.303325526362049e+00, -5.969720704891696e+00, 8.937890088762850e+01, -1.044761716291700e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rppscan_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rppscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.650869662636662e-03, 4.731443158574883e-03, 4.849142378553074e-03, 5.022252734311784e-03, 5.279490748453599e-03, 5.668144297551076e-03, 6.273980739741334e-03, 7.291544962952519e-03, 9.435278002094420e-03, 1.745338392534651e-02, 9.069372457976396e-03, 8.421826359048113e-03, 6.253189249285790e-02, 6.643176091771760e-02, 8.756137980549186e-02, 1.328505717042753e-01, 6.224342849163059e-02, 4.382977772719405e-03, 4.301094302862639e-04, 7.065553475744248e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rppscan_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rppscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.313087972898977e-02, -1.369587349665988e-02, -1.454961369792788e-02, -1.586730159831142e-02, -1.796304184441436e-02, -2.143957205228691e-02, -2.754946871307436e-02, -3.911223357441790e-02, -6.285063216831101e-02, -1.765662034932695e-01, -3.154455590380728e-01, -1.036675940637658e+00, -9.456810822109986e-01, -1.460120033036415e+00, -3.986864290340977e+00, -3.967326977016275e+01, -8.509799738453764e+02, -2.996180348228205e+03, -6.229588777006280e+04, -1.278890293196394e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rppscan_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rppscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.938767960707785e-09, 1.093233763457160e-08, 1.246817815305340e-08, 1.485934761977692e-08, 1.843188168206304e-08, 2.216664309708981e-08, 1.088142149195839e-08, -1.900601142039539e-07, -3.410535554079145e-06, -2.704530504453707e-05, 9.961885569640960e-05, -7.219078273016680e-03, 5.806119766484366e-02, 1.691655873239281e-01, 1.177780682981251e+00, 3.947089714227009e+02, 1.642221499097673e+05, 1.658030069870277e+07, 3.986392019373583e+10, 7.055187253636876e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rppscan_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rppscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.646900588676071e-06, 7.750908817358524e-06, 9.607220666037214e-06, 1.293843218319727e-05, 1.948553303137036e-05, 3.409097693485031e-05, 7.301319789556352e-05, 2.073158653842715e-04, 8.891187685109732e-04, 3.735285753543312e-03, 1.324100082128484e-03, 6.136622944860795e-02, 3.489674548720462e-02, -1.748483151545440e-02, 4.153998207540798e-01, -2.656724168689993e+01, -1.227403273664361e+03, -4.028231275252816e+03, -8.507137355437950e+04, -2.126720574698690e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rppscan_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rppscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.900588960766417e-13, 3.673508841030700e-13, 5.156438587971464e-13, 8.386017015402224e-13, 1.683054292500116e-12, 4.559348718362996e-12, 1.895404940319882e-11, 1.463661559884511e-10, 2.842189282136568e-09, 1.360672882987514e-07, -2.804580954318085e-06, 9.644247840335733e-04, 7.462770022031465e-03, 1.255861603910389e-01, 5.793250310797873e+00, -5.112219807914426e+03, -3.379239660237989e+07, -1.057586439127603e+11, -2.905482677065647e+16, -3.989726953992785e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rppscan_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rppscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.320955520236614e-10, -3.968696426711604e-10, -5.125654105457995e-10, -7.398274273238094e-10, -1.251816060598835e-09, -2.658011794039344e-09, -7.813301361355760e-09, -3.687998113037744e-08, -3.544081587895621e-07, -6.033900103341075e-06, 4.873484832041413e-05, 6.497464282750217e-04, -8.178269848497669e-04, -1.483615077166045e-01, -2.560303115302160e+00, 4.902813466012443e+02, 2.652887039358125e+05, 2.668016652694723e+07, 6.386759239458132e+10, 1.216738092452964e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rppscan_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rppscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.819295793005830e-07, 4.305225289779512e-07, 5.113468491088056e-07, 6.546439958356356e-07, 9.332324026540583e-07, 1.552329734014665e-06, 3.226563215077294e-06, 9.317224517947102e-06, 4.434457499459090e-05, 2.689870079805287e-04, -6.760203240249636e-04, -6.446543823487270e-03, -3.320996554083289e-02, 1.830243305669138e-01, 1.157887773472232e+00, -4.695235632986433e+01, -2.086601589454274e+03, -6.850646494350567e+03, -1.442142457556122e+05, -3.731173701025269e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
