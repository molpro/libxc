
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_vmt_pbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt_pbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.304567643710238e+00, -4.222914711741003e+00, -4.108617056847912e+00, -3.950534320879292e+00, -3.735650425293204e+00, -3.450766264987415e+00, -3.086430687131174e+00, -2.643900323800690e+00, -2.143616414959525e+00, -1.623186833661436e+00, -1.095858382493187e+00, -6.648996841345650e-01, -5.628249891076661e-01, -4.725715070923287e-01, -3.511705153978015e-01, -2.340677309509888e-01, -1.273614702546688e-01, -3.920540645911058e-02, -4.865433729586672e-03, -5.377875301790263e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_vmt_pbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.374914383961501e+00, -5.260268480020079e+00, -5.099509847461498e+00, -4.876595632190601e+00, -4.572416206080636e+00, -4.166815387102469e+00, -3.643735325863767e+00, -3.001769245654751e+00, -2.274335055964421e+00, -1.563752136117917e+00, -1.013426449726792e+00, -7.976217749957137e-01, -7.150021912433316e-01, -5.531128828546619e-01, -3.554072004872345e-01, -2.072134461350498e-01, -1.420340367216938e-01, -6.633897864689967e-02, -6.521330158984084e-03, -7.170500402387017e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_vmt_pbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.911113085735758e-06, -4.232186025509904e-06, -4.739313906891388e-06, -5.573413267819842e-06, -7.026710898025827e-06, -9.774048618343423e-06, -1.559514081524251e-05, -3.000756286381943e-05, -7.366296584019824e-05, -2.416439373715105e-04, -1.192474206765952e-03, -7.134510022805915e-03, -1.316307304088930e-02, -2.860090077549542e-02, -1.063060248219935e-01, -5.615923867678339e-01, -1.883270971514405e+00, 3.169404218641967e+01, 9.280278887870155e+00, 6.376382323377900e-264]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_vmt_pbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.234384462025594e-02, -1.292023164985724e-02, -1.379678973675625e-02, -1.516230320204510e-02, -1.736320139998342e-02, -2.108250807910436e-02, -2.777473406813980e-02, -4.070142438674187e-02, -6.628809652582034e-02, -1.037059164111120e-01, -1.739461478072020e-01, -5.770643449553389e-01, -6.829765515016405e-01, -1.206284726113940e+00, -2.448253947396980e+00, 2.043641339637491e+00, 6.108308953789982e+01, -2.702164440047954e+02, -1.000398697628210e+04, -6.190863068898107e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_vmt_pbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.510278751923543e-08, 2.870168921225001e-08, 3.477184724472245e-08, 4.573590814942174e-08, 6.755227029422953e-08, 1.172361268668968e-07, 2.530587048105859e-07, 7.191719066741212e-07, 2.657122513342864e-06, 6.148498738129873e-06, -9.673756338720621e-05, 1.185780945341698e-02, 3.838983426082482e-02, 1.274665017262507e-01, 6.407537432629286e-01, -4.271475519059297e+01, -7.408903565387908e+03, -9.392992693339066e+05, 6.515770981879683e+08, 2.750812867752752e-251]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_vmt_pbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.309273928761672e-14, 5.482764772623731e-14, 7.747451834147787e-14, 1.272096782908091e-13, 2.587806218310939e-13, 7.137761066161574e-13, 3.025005012658324e-12, 2.331641907733524e-11, 4.040746459824207e-10, 1.952039866174446e-08, 2.893570188749730e-06, 2.809915676712093e-04, 1.595512428140913e-03, 1.897494571124191e-02, 1.389683045075515e+00, 5.731581625911846e+02, 6.755762815430607e+05, -8.420662164462012e+08, -1.891984787480155e+14, -5.820835427001311e-243]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
