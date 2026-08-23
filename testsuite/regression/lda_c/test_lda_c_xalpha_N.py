
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_xalpha_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_xalpha", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.081498750235211e+00, -2.039452469813237e+00, -1.980526418720501e+00, -1.898880519143243e+00, -1.787589721282731e+00, -1.639396506348804e+00, -1.448530838080153e+00, -1.214083677496087e+00, -9.451070210557044e-01, -6.675113703099416e-01, -4.373087726778558e-01, -3.350881949820512e-01, -2.946845740290810e-01, -2.359174811676706e-01, -1.615855040450207e-01, -9.206973149253293e-02, -4.180734333240941e-02, -1.397641261158817e-02, -2.999300741203693e-03, -3.370887056544889e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_xalpha_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_xalpha", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.775342927316785e+00, -2.775320406369651e+00, -2.719293503567152e+00, -2.719246414711676e+00, -2.640751351296679e+00, -2.640652426399163e+00, -2.531945317715171e+00, -2.531736040719172e+00, -2.383676571126517e+00, -2.383229226352440e+00, -2.186347332562248e+00, -2.185376036969886e+00, -1.932452607688920e+00, -1.930292670535143e+00, -1.621258795880931e+00, -1.616274658559050e+00, -1.266140040879315e+00, -1.253969017425616e+00, -9.051927701247174e-01, -8.731017149792605e-01, -6.167105667532404e-01, -5.301300347931345e-01, -4.837504247822299e-01, -3.260133039201304e-01, -4.250344902940122e-01, -2.775306745588226e-01, -3.404557137273788e-01, -2.259070444470400e-01, -2.329108749341724e-01, -1.497754899529898e-01, -1.320198175901564e-01, -7.819633499888311e-02, -5.914453556552134e-02, -3.020413837637947e-02, -1.933065835135765e-02, -7.720901725905798e-03, -4.057984497189838e-03, -1.108480862465790e-03, -4.510679818455361e-04, -7.333569476979398e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_xalpha_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_xalpha", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.033134417469130e-02, 0.000000000000000e+00, -1.033151184729551e-02, -1.076162775400501e-02, -8.805254571710335e-134, -1.076200047279868e-02, -1.141129977888893e-02, -7.924729114539301e-133, -1.141215478183800e-02, -1.241313538113160e-02, 1.761050914342067e-133, -1.241518764172276e-02, -1.400539881554808e-02, -5.283152743026201e-133, -1.401065708437871e-02, -1.664760727083061e-02, -8.805254571710335e-133, -1.666240869688579e-02, -2.130945939804481e-02, -5.283152743026201e-133, -2.135717531721381e-02, -3.027509017622950e-02, -1.408840731473654e-132, -3.046209783028072e-02, -4.963941439297961e-02, 2.465471280078894e-132, -5.060769107112632e-02, -9.711984551189320e-02, 1.408840731473654e-132, -1.043903739720232e-01, -2.092316387430552e-01, -5.635362925894614e-132, -2.831557047310626e-01, -3.400536315706685e-01, 0.000000000000000e+00, -7.487200957749021e-01, -4.404958179444219e-01, -5.071826633305153e-131, -1.033161355632116e+00, -6.865447993329090e-01, -2.254145170357846e-131, -1.559303266074377e+00, -1.466934093687395e+00, 7.889508096252460e-131, -3.547387554877230e+00, -4.565747387261476e+00, -2.704974204429415e-130, -1.301419587597094e+01, -2.274892528374131e+01, -1.081989681771766e-129, -8.722826482967695e+01, -2.129594152148745e+02, 0.000000000000000e+00, -1.334916455619825e+03, -4.832472250588858e+03, 0.000000000000000e+00, -6.476401084421300e+04, -3.911164970751678e+05, -4.727285052306297e-125, -1.479651076496933e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
