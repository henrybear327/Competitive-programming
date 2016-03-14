$(function () {
    if ($("#team_submissions_table").length == 0) {
        return;
    }

    $("#team_submissions_table").dataTable({
        "paging": false,
        "lengthChange": false,
        "searching": false,
        "ordering": false,
        "info": false,
        "autoWidth": false
    });

});
