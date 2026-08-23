
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_pbe_molb0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_molb0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.318868730465003e+00, -3.256922420962729e+00, -3.170184039255713e+00, -3.050163143331035e+00, -2.886900596793349e+00, -2.670201814905213e+00, -2.392507542599169e+00, -2.053913884154105e+00, -1.668020839242515e+00, -1.260467822449439e+00, -8.507635409361152e-01, -5.484760932101839e-01, -4.776305372133370e-01, -3.968803807599467e-01, -2.893176346296578e-01, -1.828617555719928e-01, -9.248695254978145e-02, -3.148780106054725e-02, -6.577839794276268e-03, -7.276223519279851e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_pbe_molb0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_molb0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.139813049719791e+00, -4.052882701197598e+00, -3.930980800970513e+00, -3.761939296208984e+00, -3.531275648584396e+00, -3.223770401819057e+00, -2.827532220680663e+00, -2.342498266253942e+00, -1.796625123406773e+00, -1.268321340765934e+00, -8.460130213374575e-01, -6.826075858661232e-01, -6.159341333648860e-01, -4.910994157760098e-01, -3.313230770374463e-01, -1.947830309274702e-01, -1.090180913388421e-01, -4.121708330063386e-02, -8.762644001400527e-03, -9.701519993624624e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe_molb0_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_molb0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.839810768356030e-06, -3.078097927301681e-06, -3.454617027834058e-06, -4.074086282129462e-06, -5.153275409342030e-06, -7.190436564692584e-06, -1.148584646205521e-05, -2.198135340525973e-05, -5.276404191926974e-05, -1.636814542784743e-04, -7.569244771595010e-04, -2.941804756044678e-03, -2.992769400027101e-03, -1.043057689008074e-02, -4.577538473481867e-02, -2.531786945647991e-01, -9.611275700721607e-01, -1.725252482010323e+00, -2.125985542274393e+00, -2.354652311543150e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe_molb0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_molb0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.681665561668561e-03, -1.013699099844989e-02, -1.082861131043747e-02, -1.190374868605130e-02, -1.362981848651778e-02, -1.652413544597906e-02, -2.164724998861575e-02, -3.117951806934035e-02, -4.832707195455538e-02, -6.648431352926702e-02, -1.126461786002377e-01, -4.529232409846536e-01, -5.114985624142644e-01, -9.472242794943615e-01, -2.235883373982460e+00, -2.913860780537765e+00, 3.775635111809764e+00, -3.361001180150490e+02, -1.011759708004064e+04, -8.374939770128622e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe_molb0_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_molb0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.357139684335029e-08, 2.686215125694031e-08, 3.238189288729940e-08, 4.226743735608288e-08, 6.167585702675013e-08, 1.049106501096378e-07, 2.185889757747226e-07, 5.795768286156364e-07, 1.796030522251666e-06, -7.267277543922354e-07, -1.405277053240024e-04, 9.574623626945755e-03, 2.007511685449923e-02, 9.839882782089202e-02, 7.739396791440156e-01, -1.079548199024011e+01, -2.715733487130192e+03, -2.040867116267659e+05, -2.967383549184361e+07, -2.439393566892685e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe_molb0_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_molb0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.767067851053093e-14, -4.263995719954918e-14, -5.017040547996844e-14, -6.066385871069149e-14, -6.778108294521772e-14, -4.970963153153886e-15, 8.140737070386867e-13, 1.228127566921879e-11, 2.857883991093755e-10, 1.478784907630190e-08, 1.993977835643885e-06, -3.385950915623932e-04, -4.670911951175121e-03, -1.668800987284734e-02, 6.863742410460283e-03, 1.991947944864329e+02, 2.698861412449758e+05, 6.200896353220910e+08, 1.078053921426238e+13, 6.877079297713574e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
