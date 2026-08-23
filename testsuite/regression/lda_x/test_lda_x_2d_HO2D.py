
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_2d_HO2D_2_zk():
    # Prepare the input
    inp = test_data["HO2D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_2d", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.488270185974286e-01, -8.488280787371353e-01, -8.488308330114014e-01, -8.488379218963582e-01, -8.488558858587011e-01, -8.489002358003553e-01, -8.490049100470569e-01, -8.492325619134655e-01, -8.496514043694037e-01, -8.501257749137091e-01, -8.494392212988000e-01, -8.427340751595820e-01, -8.164791097893456e-01, -7.441693166551531e-01, -5.955303010966274e-01, -3.738960036058357e-01, -1.544936616315420e-01, -3.188752350016415e-02, -2.116913789203753e-03, -2.221675070124616e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_2d_HO2D_2_vrho():
    # Prepare the input
    inp = test_data["HO2D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_2d", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.274824148083050e+00, -1.271648989608302e+00, -1.275805579028763e+00, -1.270657844741550e+00, -1.277387807701114e+00, -1.269050092117550e+00, -1.279927183706587e+00, -1.266443793106539e+00, -1.283972964239123e+00, -1.262223142838833e+00, -1.290341975968725e+00, -1.255399692079465e+00, -1.300172478199541e+00, -1.244398420040753e+00, -1.314855389819391e+00, -1.226739801164578e+00, -1.335588492139207e+00, -1.198598367803241e+00, -1.362030676000769e+00, -1.154271580719507e+00, -1.389237096266650e+00, -1.085759890820182e+00, -1.402230560907855e+00, -9.830672139065029e-01, -1.369545092668868e+00, -8.365969961588398e-01, -1.242995138337503e+00, -6.437885969491940e-01, -9.803351461509787e-01, -4.207278830872159e-01, -6.035637401893463e-01, -2.108732820140493e-01, -2.446004282277856e-01, -6.869441619898939e-02, -4.967037061024047e-02, -1.111679486640444e-02, -3.257079437118142e-03, -5.776524526957929e-04, -3.388552220605878e-05, -4.744922188203298e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_2d_HO2D_2_v2rho2():
    # Prepare the input
    inp = test_data["HO2D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_2d", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.997514004813496e+00, 6.762435511073537e-131, -2.002501563151245e+00, -1.995977389759412e+00, -4.508290340715691e-131, -2.004063564403741e+00, -1.993505084452909e+00, 9.016580681431383e-131, -2.006602501577573e+00, -1.989549969628652e+00, 6.762435511073537e-131, -2.010732022479978e+00, -1.983280925996256e+00, -4.508290340715691e-131, -2.017455553653617e+00, -1.973491630045248e+00, 0.000000000000000e+00, -2.028420992562373e+00, -1.958570214466200e+00, 2.254145170357846e-131, -2.046353521878411e+00, -1.936698977839769e+00, -4.508290340715691e-131, -2.075810279451994e+00, -1.906634494425480e+00, -4.508290340715691e-131, -2.124547436300487e+00, -1.869619483863143e+00, 0.000000000000000e+00, -2.206135134924655e+00, -1.833005392897710e+00, 6.762435511073537e-131, -2.345342751192178e+00, -1.816020246928325e+00, 1.127072585178923e-130, -2.590340775735112e+00, -1.859361260247325e+00, 0.000000000000000e+00, -3.043853971699942e+00, -2.048663756542301e+00, 2.254145170357846e-131, -3.955458517807961e+00, -2.597559721762897e+00, 2.254145170357846e-131, -6.052556038798233e+00, -4.219072352940652e+00, -4.057461306644122e-130, -1.207587355377087e+01, -1.041077118270170e+01, -9.016580681431383e-130, -3.706966636260297e+01, -5.126756773071713e+01, 2.885305818058042e-129, -2.290659421238332e+02, -7.818289785782582e+02, 1.154122327223217e-128, -4.408323859072003e+03, -7.514947162345964e+04, -2.954553157691435e-126, -5.366745730417488e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
