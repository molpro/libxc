
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_s12g_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_s12g", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.342916131618669e+00, -4.257143045409756e+00, -4.137185133674622e+00, -3.971534213293835e+00, -3.747022530241043e+00, -3.451107267291905e+00, -3.077241672939674e+00, -2.634094224118289e+00, -2.150156480837529e+00, -1.646117623972804e+00, -1.112850749904720e+00, -6.642187118292956e-01, -5.714766231970145e-01, -4.708729063323120e-01, -3.544079833827904e-01, -2.353040206620098e-01, -1.206658576349313e-01, -4.093393290251082e-02, -8.542439971218188e-03, -9.448879653568016e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_s12g_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_s12g", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.659908352514607e+00, -5.535853632922829e+00, -5.360949180661391e+00, -5.116366455894024e+00, -4.778210703921486e+00, -4.318219263695569e+00, -3.709291926425105e+00, -2.952640429199587e+00, -2.160174518728484e+00, -1.536708120258787e+00, -1.034442684260664e+00, -8.226727573647278e-01, -7.541483942365946e-01, -5.588041783487870e-01, -3.394447903990226e-01, -2.272993937514776e-01, -1.420459539585482e-01, -5.368156836700929e-02, -1.138105612301063e-02, -1.259838020177270e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_s12g_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_s12g", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.401811745705832e-06, -1.603990280691485e-06, -1.943778452690247e-06, -2.553103475116848e-06, -3.747214234498955e-06, -6.376159439335531e-06, -1.302160531022000e-05, -3.207448819565159e-05, -8.916731434618784e-05, -2.648299621499447e-04, -1.196842943184695e-03, -5.051482380725511e-03, -2.905382539804406e-03, -2.564501281137306e-02, -1.254141667142101e-01, -4.628633258609250e-01, -1.277275572284922e+00, -2.021303019003151e+00, -2.413332697211610e+00, -2.664143300645519e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_s12g_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_s12g", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.418373727244687e-02, -1.508032438885878e-02, -1.649070992681351e-02, -1.879405538269334e-02, -2.274540036057374e-02, -2.990222449671344e-02, -4.314368511212129e-02, -6.379835202622397e-02, -7.093337821213494e-02, -1.548260852897461e-02, 6.906585164291350e-02, -8.454435924976341e-01, -7.117115894834606e-01, -1.908541948047411e+00, -1.511510775140779e+00, 6.081371403843894e+00, 1.323376514551983e+01, -4.473984232746232e+02, -1.315847923628314e+04, -1.087587778865342e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_s12g_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_s12g", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.915276814796625e-08, 4.715771164920632e-08, 6.141964096607393e-08, 8.914887478524044e-08, 1.497402613704842e-07, 3.027852926648898e-07, 7.494146713377595e-07, 2.069704518837865e-06, 3.529685960578000e-06, -2.873775016573344e-05, -7.556015012174333e-04, 3.231150589275335e-02, 3.727520766603236e-02, 3.850726975546317e-01, -1.670713757189170e-01, -6.741563318424146e+01, -4.165507274188099e+03, -2.446456991689594e+05, -3.375682937409016e+07, -2.760156581928671e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_s12g_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_s12g", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.081173932460737e-13, -3.938826420097245e-13, -5.584806175023239e-13, -9.143756787161952e-13, -1.818287197341872e-12, -4.628536692749482e-12, -1.527248370308375e-11, -4.966178336115996e-11, 4.495925790326242e-10, 3.566926265568917e-08, 4.658077575889574e-06, -1.720124350161276e-03, -1.034800606686745e-02, -8.358753995471274e-02, 2.509179133581457e+00, 6.448743999768211e+02, 3.999343360359485e+05, 7.399704163987380e+08, 1.225826534264145e+13, 7.781277715861015e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
