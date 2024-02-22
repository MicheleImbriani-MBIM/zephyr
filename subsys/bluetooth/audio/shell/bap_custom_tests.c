#include <shell.h>

static int cmd_gatt_write_no_resp(const struct shell *sh, size_t argc, char **argv)
{
	shell_print(sh, "HEHE");
}

static int cmd_bap_custom_tests(const struct shell *sh, size_t argc, char **argv)
{
	if (argc > 1) {
		shell_error(sh, "%s unknown parameter: %s", argv[0], argv[1]);
	} else {
		shell_error(sh, "%s Missing subcommand", argv[0]);
	}

	return -ENOEXEC;
}

// static int cmd_default_handler(const struct shell *sh, size_t argc, char **argv)
// {
// 	if (argc == 1) {
// 		shell_help(sh);
// 		return SHELL_CMD_HELP_PRINTED;
// 	}

// 	shell_error(sh, "%s unknown parameter: %s", argv[0], argv[1]);

// 	return -EINVAL;
// }

SHELL_STATIC_SUBCMD_SET_CREATE(
	bap_tests_cmds,
	// SHELL_CMD_ARG(gatt_write_no_response, NULL, "GATT Write no response",
	//         cmd_bap_custom_tests_gatt_write_no_resp, 0, 0),
	// ...
	SHELL_CMD(gatt_write_no_resp, NULL, "GATT Write No Response", cmd_gatt_write_no_resp),
	SHELL_SUBCMD_SET_END);

SHELL_CMD_REGISTER(BAP_tests, &bap_tests_cmds,
            "Commands for missing BAP Tests",
            NULL);