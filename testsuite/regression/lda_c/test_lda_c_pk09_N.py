
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_pk09_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pk09", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.182035830586474e-01, -1.176271595149616e-01, -1.167982715148291e-01, -1.156068116038912e-01, -1.138955450264618e-01, -1.114415414168178e-01, -1.079330874596145e-01, -1.029465313299409e-01, -9.594398894943681e-02, -8.637554856653867e-02, -7.392824575858586e-02, -6.057949368223978e-02, -5.671116956979306e-02, -5.260691186631106e-02, -4.420477623791037e-02, -3.234080773180480e-02, -1.913978482189092e-02, -8.052942515924614e-03, -2.101415916239422e-03, -3.983094981609103e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_pk09_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pk09", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.276144919239813e-01, -1.276163197331712e-01, -1.270443557955924e-01, -1.270482381959348e-01, -1.262224806818104e-01, -1.262308231266914e-01, -1.250367686629164e-01, -1.250549971523127e-01, -1.233243338704216e-01, -1.233651412254057e-01, -1.208475219178334e-01, -1.209421550994912e-01, -1.172565173023434e-01, -1.174875741879545e-01, -1.120236462554264e-01, -1.126319744575657e-01, -1.042931647690197e-01, -1.060793157284647e-01, -9.242532144993813e-02, -9.848174220496055e-02, -7.353599472712423e-02, -9.594410007562527e-02, -5.505754839047166e-02, -1.098214940823587e-01, -5.136375098999645e-02, -1.082983264550034e-01, -4.801467659816812e-02, -9.860772127471834e-02, -4.051436631341328e-02, -8.801595354200874e-02, -2.988767476162559e-02, -7.453106926370484e-02, -1.862223950240669e-02, -5.431062723406230e-02, -8.641634187311127e-03, -3.072039374132483e-02, -2.696990132949943e-03, -2.861208707591924e-03, -5.143809732987127e-04, 7.401269787398117e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_pk09_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pk09", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.673878001455110e-04, -4.711056501388100e-04, 3.674066624469189e-04, 3.883839965725304e-04, -4.988889678474990e-04, 3.884265723836847e-04, 4.206415293093821e-04, -5.416720061433537e-04, 4.207413647828574e-04, 4.716388995794668e-04, -6.095383986368400e-04, 4.718861896537023e-04, 5.556263917896556e-04, -7.218722837638429e-04, 5.562891244307016e-04, 7.022269382251145e-04, -9.194738287507323e-04, 7.042158973144196e-04, 9.800023102361191e-04, -1.298597598055354e-03, 9.870248648826032e-04, 1.569508939273758e-03, -2.121456968091840e-03, 1.600803577175891e-03, 3.016759421136997e-03, -4.242917426836914e-03, 3.210677366445318e-03, 7.044215375141854e-03, -1.106889732254063e-02, 8.906455108604633e-03, 1.548103352630182e-02, -3.685948022526269e-02, 4.179391186431670e-02, 1.693923166892533e-02, -9.871248431488654e-02, 2.378925377882520e-01, 2.189017440116158e-02, -1.461289982327325e-01, 3.858863483746334e-01, 4.065007243385085e-02, -2.608860829267635e-01, 6.464854156993383e-01, 9.814572225336730e-02, -7.520104109430403e-01, 2.004527223677567e+00, 2.695476510486120e-01, -3.519402334838726e+00, 1.110494015260527e+01, 6.848165757539177e-01, -3.353388511796303e+01, 1.601787331929862e+02, -3.749876919922441e+01, -3.790511275326145e+02, 1.839835911054201e+03, -3.170765783188999e+03, 2.643006339221296e+04, -1.609852952124438e+06, -3.453407517673720e+05, 1.084272661120403e+07, -2.285127476085378e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
