
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_lak_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_lak", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.884871346561372e+00, -4.786000272678241e+00, -4.647418830209311e+00, -4.455365889241564e+00, -4.193491705697018e+00, -3.844576671390769e+00, -3.394678408458162e+00, -2.840659451036709e+00, -2.200321072647273e+00, -1.505337640616601e+00, -7.456202254804264e-01, -5.161398678853716e-01, -5.758932067725384e-01, -4.932643837113976e-01, -3.317512504166503e-01, -1.686057421780208e-01, -5.928832745252431e-02, -1.969823033271611e-02, -2.784750357152851e-03, -1.281202311489067e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_lak_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_lak", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.456192504624034e+00, -6.323474100757243e+00, -6.137392185498644e+00, -5.879384344358511e+00, -5.527302901875032e+00, -5.057597228960439e+00, -4.450593192367221e+00, -3.699450941448713e+00, -2.814324601494268e+00, -1.722129561877976e+00, -1.043982357519731e+00, -7.464831701535767e-01, -9.047230450542540e-01, -6.723099727269313e-01, -3.992827977877385e-01, -1.129485344149049e-01, -4.754515012113496e-02, -2.896085973799270e-02, -4.980543269718068e-03, -2.468737133540616e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_lak_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_lak", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.839357830806578e-06, -1.997414835907942e-06, -2.248986448575500e-06, -2.667645311926758e-06, -3.410557490139341e-06, -4.856555150057909e-06, -8.074863402251957e-06, -1.687651563487945e-05, -5.275748730622988e-05, -4.575325079755831e-04, -7.067110531193581e-04, 5.397195279996694e-04, -2.106132243892855e-02, -4.977429611875008e-02, -2.315548804838964e-01, -2.422241971114362e+00, -5.762985082411295e+00, 5.882684657074175e+00, 3.451078068847013e+02, 1.607893728783937e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_lak_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_lak", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.793729320737687e-03, 2.857972281359004e-03, 2.953342897060879e-03, 3.096858893349334e-03, 3.316949799543998e-03, 3.663271817530072e-03, 4.228593512864041e-03, 5.228603732238258e-03, 7.646973556936847e-03, 2.231027004934110e-02, 9.907881000570183e-03, 4.492830203309654e-03, 7.708437116433814e-02, 8.685163696576587e-02, 1.257637092072806e-01, 2.323802824911701e-01, 4.124194713972626e-02, 7.493861267673899e-05, 8.988714276439966e-09, 1.743837209557021e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_lak_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_lak", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.267681405619085e-02, -1.321363874483611e-02, -1.402282677769839e-02, -1.526578778323023e-02, -1.722241919412308e-02, -2.038953455019022e-02, -2.561182325332769e-02, -3.387825854231487e-02, -4.270006599816374e-02, -1.038967943201025e-01, -2.290561721867895e-01, -1.059736005692184e+00, -7.486096833532085e-01, -1.758790482194236e+00, -4.610602132143804e+00, -5.324214304022200e+01, -7.989227793654018e+02, -1.777246227220769e+02, -1.235500536484059e+04, -5.769800194333901e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_lak_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_lak", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.195625825236380e-09, 3.222420383176028e-09, 3.078661131305183e-09, 2.252095861171341e-09, -1.387781251098497e-09, -1.839672367608379e-08, -1.153050498256315e-07, -8.657935834276862e-07, -1.006094585823883e-05, -1.734950285844577e-04, -4.376349193625296e-04, 1.740425728099735e-02, 4.952810062770904e-02, 3.907470717716118e-01, 4.219516125050538e-01, 4.092200914969698e+02, 1.601695039986950e+05, -2.241821954764195e+04, 1.781968980681943e+09, 7.692728678548734e+13]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_x_lak_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_lak", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.838460986510016e-06, 1.023826685216394e-05, 1.263433554218429e-05, 1.706381653590436e-05, 2.620727763718182e-05, 4.823540525946449e-05, 1.133898165171600e-04, 3.619339771356780e-04, 1.701742972417451e-03, 1.146036218966868e-02, 5.556971997871693e-03, 3.842639721308599e-02, -4.705433070949023e-02, -1.999866220608888e-01, 1.350303501030723e+00, -1.802675073435947e+01, -1.217798597834467e+03, -9.788478509724825e+01, -2.454058545954507e+00, -7.336372778243117e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_lak_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_lak", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.054984696578788e-13, 3.910238021015526e-13, 5.579414828414688e-13, 9.312977089045391e-13, 1.949791105019356e-12, 5.658779496647250e-12, 2.614191155465189e-11, 2.301958749389773e-10, 5.046203565795947e-09, 3.876244519581817e-07, -1.568011012802878e-05, -2.381650705052970e-03, -3.508528280908970e-03, 1.806126782448567e-01, 1.623103801992319e+01, -2.284124052171734e+03, -3.409152891851608e+07, -2.254296027407526e+09, -9.243554093376024e+14, -2.800586616446512e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_lak_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_lak", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.387047395287973e-10, -5.286693789536967e-10, -6.914901343981225e-10, -1.017790517980558e-09, -1.775751247309740e-09, -3.955307591195899e-09, -1.246526151006786e-08, -6.378061165943426e-08, -6.588819967938876e-07, -1.797072147205934e-05, 2.172754884896634e-04, 9.682708841900041e-04, 1.123563789511691e-02, -3.309149407638151e-01, -8.090539772458511e+00, 2.011752482209376e+02, 2.702016062574388e+05, 6.793102257905180e+05, 1.926970447905964e+06, 4.297747786792319e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_x_lak_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_lak", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.553308584771004e-07, 7.422701367198046e-07, 8.878631130107537e-07, 1.148520002411396e-06, 1.662222810263003e-06, 2.824263347955607e-06, 6.026547304389253e-06, 1.778206118157598e-05, 8.622981234652930e-05, 8.362695388627885e-04, -2.803913022536455e-03, -4.609621534364641e-03, -1.819216923938446e-02, 5.582569396591204e-01, 4.101477382177168e+00, -1.787864441799208e+01, -2.144370514549754e+03, -1.781745418527929e+02, -4.454968782761564e+00, -1.335284002109798e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
