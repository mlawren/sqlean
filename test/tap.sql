.load build/last/tap
.load build/last/ipaddr

select
--    tap_subtest('This is a subtest'),
    tap_is(1,1,'integers'),
    tap_is(1, 1.0, 'type mismatch'),
    tap_is(ipfamily('192.168.16.12'), 4, 'ipfamily'),
    tap_isnt(1, 3, 'by value'),
    tap_isnt(1.0, 1, 'by type'),
    tap_isnt(1, 1, 'by type'),
--    tap_is(tap_is(2,3, 'should fail'),'stuff', 'type mismatch'),
    tap_done()
;
