
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_vbh_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vbh", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.330587117416068e-01, -1.325472981961437e-01, -1.318126464822683e-01, -1.307579902204359e-01, -1.292453865478596e-01, -1.270790295834152e-01, -1.239826763471500e-01, -1.195705538476355e-01, -1.133178329699385e-01, -1.045713340216620e-01, -9.247712612270696e-02, -7.841792431678621e-02, -7.451694339894849e-02, -7.043268825827824e-02, -6.166655652465357e-02, -4.871536755176704e-02, -3.302351454480041e-02, -1.752227841399571e-02, -5.829888955299387e-03, -8.066244001188767e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_vbh_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vbh", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.414116877883810e-01, -1.414139525224744e-01, -1.408980621608469e-01, -1.409028726410144e-01, -1.401592645600249e-01, -1.401696013734863e-01, -1.390964274182281e-01, -1.391190143059651e-01, -1.375667351326006e-01, -1.376173024473655e-01, -1.353622713150377e-01, -1.354795507669701e-01, -1.321739672421605e-01, -1.324603633006113e-01, -1.275168806900657e-01, -1.282709918547530e-01, -1.205263112689111e-01, -1.227394986819718e-01, -1.092825232437708e-01, -1.167622394924104e-01, -8.996680276380947e-02, -1.170599273112108e-01, -7.136300223282281e-02, -1.318940827538032e-01, -6.807818684139293e-02, -1.296457461238818e-01, -6.510454627820675e-02, -1.195165046365527e-01, -5.813081766047716e-02, -1.069111647278165e-01, -4.773666869902023e-02, -8.890878790526607e-02, -3.482907324156011e-02, -6.225114045983304e-02, -2.048634788853864e-02, -2.851095324645520e-02, -7.438034905563456e-03, -5.023083873161514e-03, -1.070250398531139e-03, -2.378298328235956e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_vbh_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vbh", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.727256380788849e-04, -5.662037608086638e-04, 4.727490101607050e-04, 4.999937864275169e-04, -5.993799540087370e-04, 5.000465453858361e-04, 5.419110825645468e-04, -6.504558477205398e-04, 5.420348085287844e-04, 6.082326840009927e-04, -7.314520654866713e-04, 6.085391911675407e-04, 7.175768557910725e-04, -8.654629746108418e-04, 7.183984292444986e-04, 9.087153203931993e-04, -1.101066827051084e-03, 9.111814426803616e-04, 1.271545581233171e-03, -1.552783558391000e-03, 1.280253762134511e-03, 2.043164819438921e-03, -2.532274863058182e-03, 2.081958336520279e-03, 3.940981397078086e-03, -5.053552297792247e-03, 4.180917743378307e-03, 9.219265322872995e-03, -1.312156468490601e-02, 1.150518727397279e-02, 1.970777311358235e-02, -4.206003617866124e-02, 5.025196115877947e-02, 1.705355167746474e-02, -9.311155054240899e-02, 2.145365404726774e-01, 2.056558867550949e-02, -1.330007859462392e-01, 3.285320146229994e-01, 3.764931884638845e-02, -2.394727122740435e-01, 5.502093686205362e-01, 7.714449890106732e-02, -6.588233411215956e-01, 1.547401849893246e+00, 1.047226203669699e-01, -2.930756476993372e+00, 7.481491789728045e+00, -2.025208087066586e+00, -2.260097215022089e+01, 6.103060690140532e+01, -9.634544652844838e+01, -3.165494115097737e+02, 5.331306363450839e+02, -6.616882962737518e+03, -6.242836512343157e+03, -6.285197079875123e+04, -8.896633178171670e+05, -1.110208482914711e+05, -3.280183203627463e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
