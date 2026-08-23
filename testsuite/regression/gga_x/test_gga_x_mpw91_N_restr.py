
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_mpw91_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mpw91", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.324563281213554e+00, -4.242839065344814e+00, -4.128412544192884e+00, -3.970088368557072e+00, -3.754736364158609e+00, -3.468915182947925e+00, -3.102652910896711e+00, -2.656124161050041e+00, -2.148021605465296e+00, -1.616676492978504e+00, -1.087898239257047e+00, -6.684165581534930e-01, -5.650584802457355e-01, -4.750194071843798e-01, -3.509585143166795e-01, -2.316462801100431e-01, -1.356050697271423e-01, -3.564838234739414e-02, -6.867002892365148e-04, -1.685628471126951e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_mpw91_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mpw91", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.377969830234835e+00, -5.264322494628233e+00, -5.105051871448382e+00, -4.884382650753501e+00, -4.583639186192516e+00, -4.183364771418168e+00, -3.668535273339270e+00, -3.038649522732927e+00, -2.324315773411828e+00, -1.609596589756701e+00, -1.038183402377965e+00, -8.014184392241316e-01, -7.145514079084631e-01, -5.575199291107324e-01, -3.651166284321696e-01, -2.025059009017380e-01, -1.233796116159948e-01, -9.147706619372961e-02, -2.528655993838896e-03, -6.139453824224555e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_mpw91_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mpw91", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.164394534802112e-06, -4.489485728482055e-06, -5.000306814100011e-06, -5.834197365088396e-06, -7.271426966148576e-06, -9.946232643604616e-06, -1.549028199244063e-05, -2.882763607238195e-05, -6.809778974868222e-05, -2.197027553761409e-04, -1.098266746298279e-03, -7.206127127930589e-03, -1.443690125477832e-02, -2.817618113777082e-02, -9.689086290939142e-02, -5.695118052127713e-01, -3.892944118161322e+00, 9.902685011187241e+01, 4.391821660294622e+02, 8.228940294918664e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_mpw91_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mpw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.194910381908924e-02, -1.248123499501840e-02, -1.328695676621440e-02, -1.453415305809906e-02, -1.652588323015173e-02, -1.984807942806381e-02, -2.572673002097021e-02, -3.693983897335695e-02, -6.006474470193467e-02, -1.092947315673757e-01, -2.350766461962625e-01, -5.405667708369009e-01, -6.706969903283599e-01, -1.111283759297600e+00, -2.306378273461330e+00, -3.733696397563100e+00, 9.984571401791406e+01, -1.517339842226770e+03, -2.365941712254747e+04, -4.209381388089934e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_mpw91_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mpw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.080627313910643e-08, 2.359246450136475e-08, 2.824065554447917e-08, 3.650486040348198e-08, 5.258026110282908e-08, 8.802972537352521e-08, 1.807903928530110e-07, 4.836934447399715e-07, 1.746486264906672e-06, 7.354276446497027e-06, 5.239934614825964e-05, 8.765158849737166e-03, 3.396360208155682e-02, 8.961604397110372e-02, 4.615522730824291e-01, -1.105659419517362e+01, -9.607365197108102e+03, 1.284279941484705e+06, 5.638192439139787e+09, 7.779354208946613e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_mpw91_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mpw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.094270031061937e-13, 1.365010544413680e-13, 1.874559879280595e-13, 2.953377659184177e-13, 5.658339428902435e-13, 1.430280619828197e-12, 5.338676080060551e-12, 3.427807017589008e-11, 4.631172096372905e-10, 1.703808450745204e-08, 2.288109968382190e-06, 5.415275898234384e-04, 4.774511426654766e-03, 3.205231284990163e-02, 1.381985388712310e+00, 4.084927728373823e+02, 1.009574318394801e+06, -1.213821293914191e+10, -2.093303047379994e+15, -2.245699838751428e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
