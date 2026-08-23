
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_bkl1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bkl1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.501811594355098e+00, -4.423291189595529e+00, -4.313528635782162e+00, -4.162027629907374e+00, -3.956720707422399e+00, -3.685783583160910e+00, -3.341588983326038e+00, -2.926832632816282e+00, -2.457467882260470e+00, -1.938581770333077e+00, -1.325289818356944e+00, -7.130224125506968e-01, -5.819910263945758e-01, -5.142245078483269e-01, -4.113385887823789e-01, -2.818325811593315e-01, -1.289465104313034e-01, -3.634991888304174e-02, -4.865219059331147e-03, -5.377875301790263e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_bkl1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bkl1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.147687220342545e+00, -5.030863347074806e+00, -4.867112316965803e+00, -4.640214145803697e+00, -4.331067491910720e+00, -3.920252437804367e+00, -3.394934317551765e+00, -2.765210689401917e+00, -2.101281635122707e+00, -1.573664292630474e+00, -1.112581555003960e+00, -7.481500936820119e-01, -6.919634396616077e-01, -5.137235627794600e-01, -3.371289914108100e-01, -2.876865912815734e-01, -1.778902907813115e-01, -6.096188055233625e-02, -6.516119652084855e-03, -7.170500402387017e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bkl1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bkl1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.171069868018097e-06, -9.907802332736204e-06, -1.106780313118059e-05, -1.296652175515479e-05, -1.624956341322320e-05, -2.237791729766317e-05, -3.507683172369376e-05, -6.519593458530930e-05, -1.482977092123242e-04, -4.068778863026721e-04, -1.743151539268713e-03, -1.625296637676555e-02, -3.121610753481666e-02, -6.386851662208599e-02, -1.991209020521722e-01, -4.717034397147103e-01, 4.041331702384398e-01, 2.815672615804714e+01, 7.939558891570553e+00, 6.504303410710495e-261]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bkl1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bkl1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.454493410386644e-02, -1.524707724232126e-02, -1.631078997921098e-02, -1.795580219879722e-02, -2.056817210415546e-02, -2.484073280332886e-02, -3.192768532281750e-02, -4.255526001170233e-02, -4.443778573351149e-02, 8.116315431326215e-02, 4.789469844131003e-01, -6.764572779961668e-01, -7.901128359500994e-01, -1.366203291563500e+00, -4.415294856856402e-01, 2.519749405240140e+01, -5.128594484845602e+01, -4.910344993433088e+02, -9.627621885406503e+03, -6.190863068898107e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bkl1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bkl1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.325808815067716e-08, 6.048491969214939e-08, 7.252340004584802e-08, 9.384234369135091e-08, 1.348894425908627e-07, 2.229788660794867e-07, 4.358665288093622e-07, 9.526575435272901e-07, 3.344020929382781e-07, -6.846958554319355e-05, -1.890479663163255e-03, 2.196999257535143e-02, 8.513099561090670e-02, 2.097184051644604e-01, -1.164416551714856e+00, -1.790372544125063e+02, -6.165222739793405e+02, -3.162228061907400e+05, 5.507608821296507e+08, 2.773753675549420e-248]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bkl1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bkl1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.611855157622703e-13, 2.050181305911950e-13, 2.895693885293822e-13, 4.751146050579773e-13, 9.653535223925760e-13, 2.656979475010459e-12, 1.121337489572913e-11, 8.562032926830965e-11, 1.446229799052786e-09, 6.458691324026413e-08, 8.888360072458580e-06, 1.044788036314974e-03, 5.979430581180960e-03, 7.020985304969928e-02, 4.831080104135808e+00, 1.248005209186046e+03, 4.598054466429415e+03, -1.915883673018308e+09, -1.600454497648446e+14, -5.869433716558712e-240]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
