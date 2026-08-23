
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_corrksdt_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_corrksdt", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.270595102341961e+00, -4.186004892998516e+00, -4.067440763333554e+00, -3.903132465526602e+00, -3.679104097303826e+00, -3.380666678372093e+00, -2.996041850381056e+00, -2.523084699141859e+00, -1.979420696428099e+00, -1.415776408070163e+00, -9.372521961509743e-01, -6.950117096143552e-01, -6.117761562016771e-01, -4.994893395766337e-01, -3.500535699339410e-01, -2.061849095162990e-01, -9.847900933035325e-02, -3.533096213413722e-02, -8.213017815286106e-03, -9.833493377214033e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_corrksdt_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_corrksdt", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.666403731809287e+00, -5.553754752438879e+00, -5.395867498630937e+00, -5.177074530636914e+00, -4.878778839600677e+00, -4.481448760615285e+00, -3.969456427685397e+00, -3.340051077823356e+00, -2.616885133314022e+00, -1.867769293905463e+00, -1.232741173902526e+00, -9.119285667944015e-01, -8.018657465426468e-01, -6.535865881420879e-01, -4.567519039096548e-01, -2.681219067166737e-01, -1.278413277139125e-01, -4.603088120997059e-02, -1.079875101622545e-02, -1.304189601668534e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_corrksdt_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_corrksdt", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.037946949969593e-02, -1.081266603043679e-02, -1.146691327061000e-02, -1.247623870126685e-02, -1.408155534969462e-02, -1.674880654805560e-02, -2.146643257210713e-02, -3.058853774479291e-02, -5.057112595901534e-02, -1.018442621075588e-01, -2.438009325950723e-01, -4.633480462989745e-01, -6.110014906275649e-01, -9.518366333991437e-01, -2.093647804446030e+00, -6.953054743502202e+00, -3.879725763183444e+01, -4.306299054228303e+02, -1.183458655267676e+04, -1.099344709845072e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
