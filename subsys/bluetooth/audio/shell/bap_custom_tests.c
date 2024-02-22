#include <shell.h>

static int cmd_bap_custom_tests_gatt_write_no_resp(void)
{
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

SHELL_STATIC_SUBCMD_SET_CREATE(bap_tests_cmds,
			       SHELL_CMD_ARG(gatt_write_no_response, NULL, "GATT Write no response",
					     cmd_bap_custom_tests_gatt_write_no_resp, 0, 0),
			       // ...
);

// SHELL_CMD_ARG_REGISTER(cmd_bap_custom_tests, &bap_custom_tests_cmds,
// 		       "Bluetooth BAP broadcast assistant client shell commands",
// 		       cmd_bap_broadcast_assistant, 1, 1);

SHELL_CMD_REGISTER(BAP_tests, &bap_tests_cmds, "Commands for missing BAP Tests",
		   cmd_default_handler);